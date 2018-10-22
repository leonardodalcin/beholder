// local packages
#include "imageloader.hpp"
// libraries
#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#endif

image_loader::image_loader()
    : imageLabel(new QLabel), scrollArea(new QScrollArea), scaleFactor(1) {
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(false);
    setCentralWidget(scrollArea);

    createActions();

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

bool image_loader::loadFile(const QString &fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
	QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
				 tr("Cannot load %1: %2")
				     .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
	return false;
    }

    setImage(newImage);

    setWindowFilePath(fileName);

    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
				.arg(QDir::toNativeSeparators(fileName))
				.arg(image.width())
				.arg(image.height())
				.arg(image.depth());
    statusBar()->showMessage(message);
    return true;
}

void image_loader::setImage(const QImage &newImage) {
    image = newImage;
    imageLabel->setPixmap(QPixmap::fromImage(image));

    scaleFactor = 1.0;

    scrollArea->setVisible(true);
    printAct->setEnabled(true);
    fitToWindowAct->setEnabled(true);
    updateActions();

    if (!fitToWindowAct->isChecked())
	imageLabel->adjustSize();
}

bool image_loader::saveFile(const QString &fileName) {
    QImageWriter writer(fileName);

    if (!writer.write(image)) {
	QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
				 tr("Cannot write %1: %2")
				     .arg(QDir::toNativeSeparators(fileName)),
				 writer.errorString());
	return false;
    }
    const QString message = tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode) {
    static bool firstDialog = true;

    if (firstDialog) {
	firstDialog = false;
	const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
	dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
						  ? QImageReader::supportedMimeTypes()
						  : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
	mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
	dialog.setDefaultSuffix("jpg");
}

void image_loader::open() {
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {
    }
}

void image_loader::saveAs() {
    QFileDialog dialog(this, tr("Save File As"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

    while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first())) {
    }
}

void image_loader::print() {
    Q_ASSERT(imageLabel->pixmap());
#if QT_CONFIG(printdialog)
    //! [6] //! [7]
    QPrintDialog dialog(&printer, this);
    //! [7] //! [8]
    if (dialog.exec()) {
	QPainter painter(&printer);
	QRect rect = painter.viewport();
	QSize size = imageLabel->pixmap()->size();
	size.scale(rect.size(), Qt::KeepAspectRatio);
	painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
	painter.setWindow(imageLabel->pixmap()->rect());
	painter.drawPixmap(0, 0, *imageLabel->pixmap());
    }
#endif
}

void image_loader::copy() {
#ifndef QT_NO_CLIPBOARD
    QGuiApplication::clipboard()->setImage(image);
#endif  // !QT_NO_CLIPBOARD
}

#ifndef QT_NO_CLIPBOARD
static QImage clipboardImage() {
    if (const QMimeData *mimeData = QGuiApplication::clipboard()->mimeData()) {
	if (mimeData->hasImage()) {
	    const QImage image = qvariant_cast<QImage>(mimeData->imageData());
	    if (!image.isNull())
		return image;
	}
    }
    return QImage();
}
#endif  // !QT_NO_CLIPBOARD

void image_loader::paste() {
#ifndef QT_NO_CLIPBOARD
    const QImage newImage = clipboardImage();
    if (newImage.isNull()) {
	statusBar()->showMessage(tr("No image in clipboard"));
    } else {
	setImage(newImage);
	setWindowFilePath(QString());
	const QString message = tr("Obtained image from clipboard, %1x%2, Depth: %3")
				    .arg(newImage.width())
				    .arg(newImage.height())
				    .arg(newImage.depth());
	statusBar()->showMessage(message);
    }
#endif  // !QT_NO_CLIPBOARD
}

void image_loader::zoomIn() {
    scaleImage(1.25);
}

void image_loader::zoomOut() {
    scaleImage(0.8);
}

void image_loader::normalSize() {
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void image_loader::fitToWindow() {
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow)
	normalSize();
    updateActions();
}

void image_loader::about() {
    QMessageBox::about(this, tr("About Image Viewer"),
		       tr("<p><b>Beholder</b> loager.</p>"));
}

void image_loader::createActions() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAct = fileMenu->addAction(tr("&Open..."), this, &image_loader::open);
    openAct->setShortcut(QKeySequence::Open);

    saveAsAct = fileMenu->addAction(tr("&Save As..."), this, &image_loader::saveAs);
    saveAsAct->setEnabled(false);

    printAct = fileMenu->addAction(tr("&Print..."), this, &image_loader::print);
    printAct->setShortcut(QKeySequence::Print);
    printAct->setEnabled(false);

    fileMenu->addSeparator();

    QAction *exitAct = fileMenu->addAction(tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+Q"));

    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

    copyAct = editMenu->addAction(tr("&Copy"), this, &image_loader::copy);
    copyAct->setShortcut(QKeySequence::Copy);
    copyAct->setEnabled(false);

    QAction *pasteAct = editMenu->addAction(tr("&Paste"), this, &image_loader::paste);
    pasteAct->setShortcut(QKeySequence::Paste);

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    zoomInAct = viewMenu->addAction(tr("Zoom &In (25%)"), this, &image_loader::zoomIn);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);
    zoomInAct->setEnabled(false);

    zoomOutAct = viewMenu->addAction(tr("Zoom &Out (25%)"), this, &image_loader::zoomOut);
    zoomOutAct->setShortcut(QKeySequence::ZoomOut);
    zoomOutAct->setEnabled(false);

    normalSizeAct = viewMenu->addAction(tr("&Normal Size"), this, &image_loader::normalSize);
    normalSizeAct->setShortcut(tr("Ctrl+S"));
    normalSizeAct->setEnabled(false);

    viewMenu->addSeparator();

    fitToWindowAct = viewMenu->addAction(tr("&Fit to Window"), this, &image_loader::fitToWindow);
    fitToWindowAct->setEnabled(false);
    fitToWindowAct->setCheckable(true);
    fitToWindowAct->setShortcut(tr("Ctrl+F"));

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    helpMenu->addAction(tr("&About"), this, &image_loader::about);
    helpMenu->addAction(tr("About &Qt"), &QApplication::aboutQt);
}

void image_loader::updateActions() {
    saveAsAct->setEnabled(!image.isNull());
    copyAct->setEnabled(!image.isNull());
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}

void image_loader::scaleImage(double factor) {
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}
void image_loader::adjustScrollBar(QScrollBar *scrollBar, double factor) {
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep() / 2)));
}
