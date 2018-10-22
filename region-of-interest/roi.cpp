// local packages
#include "roi.hpp"
// libraries
#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QMouseEvent>
#include <QPainter>

roi::roi(QWidget *parent)
    : QLabel(parent) {
    selectionStarted = false;

    QAction *saveAction = contextMenu.addAction("Save");

    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveSlot()));
}

roi::~roi() {
}

void roi::paintEvent(QPaintEvent *e) {
    QLabel::paintEvent(e);
    QPainter painter(this);
    painter.setPen(QPen(QBrush(QColor(0, 0, 0, 180)), 1, Qt::DashLine));
    painter.setBrush(QBrush(QColor(255, 255, 255, 120)));
    painter.drawRect(selectionRect);
    painter.setBrush(QBrush(QColor(255, 255, 255, 120)));

    painter.drawRect(selectionRect);
}

void roi::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::RightButton) {
	if (selectionRect.contains(e->pos())) contextMenu.exec(this->mapToGlobal(e->pos()));
    } else {
	selectionStarted = true;
	selectionRect.setTopLeft(e->pos());
	selectionRect.setBottomRight(e->pos());
    }
}

void roi::mouseMoveEvent(QMouseEvent *e) {
    if (selectionStarted) {
	selectionRect.setBottomRight(e->pos());
	repaint();
    }
}

void roi::mouseReleaseEvent(QMouseEvent *e) {
    selectionStarted = false;
}

void roi::saveSlot() {
    QString fileName = QFileDialog::getSaveFileName(this, QObject::tr("Save File"),
						    "/home",
						    QObject::tr("Images (*.jpg)"));
    this->pixmap()->copy(selectionRect).save(fileName);
}
