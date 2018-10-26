// local packages
#include "roi.hpp"
// libraries
#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
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

void roi::set_path(std::string p) { _path = p; }
void roi::set_dir(std::string d) { _dir = d; }
void roi::saveSlot() {
    int x1, y1, x2, y2;
    selectionRect.getCoords(&x1, &y1, &x2, &y2);

    std::string roi_path_str  = _dir + "/save.json";
    QString roi_path = QString::fromUtf8(roi_path_str.c_str());

    QFile saveFile(roi_path);
    saveFile.open(QFile::WriteOnly);
    QJsonObject j;
    j["image_path"] = _path.c_str();
    j["x1"] = x1;
    j["y1"] = y1;
    j["x2"] = x2;
    j["y2"] = y2;
    QJsonDocument saveDoc(j);
    saveFile.write(saveDoc.toJson());
}
