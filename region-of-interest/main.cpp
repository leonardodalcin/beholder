// local packages
#include "roi.hpp"
// libraries
#include <QApplication>
#include <QCommandLineParser>
#include <QFileDialog>
#include <QPixmap>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    roi _roi;

    QString fileName = QFileDialog::getOpenFileName(&_roi, QObject::tr("Open File"),
						    "/home",
						    QObject::tr("Images (*.png *.xpm *.jpg)"));
    QPixmap pixmap(fileName);
    _roi.setPixmap(fileName);
    _roi.resize(pixmap.size());
    _roi.show();

    return a.exec();
}
