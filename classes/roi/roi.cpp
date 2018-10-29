//
// Created by leonardo on 29/10/18.
//

// local packages
#include "headers/roi/roi.hpp"
// libraries
#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMouseEvent>
#include <QPainter>

roi::roi(QWidget *parent)
        : QLabel(parent) {
    selectionStarted = false;

    QAction *save_action = contextMenu.addAction("Save all");
    QAction *add_action = contextMenu.addAction("Add roi");
    QAction *remove_action = contextMenu.addAction("Remove roi");

    connect(save_action, SIGNAL(triggered()), this, SLOT(save_slot()));
    connect(add_action, SIGNAL(triggered()), this, SLOT(add_slot()));
    connect(remove_action, SIGNAL(triggered()), this, SLOT(remove_slot()));
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
void roi::add_slot() {
    selected_rois.push_back(selectionRect);
}

void roi::remove_slot() {
    selected_rois.pop_back();
}

void roi::save_slot() {
    std::string roi_path_str = _dir + "/save.json";
    QString roi_path = QString::fromUtf8(roi_path_str.c_str());

    QFile saveFile(roi_path);
    saveFile.open(QFile::WriteOnly);
    QJsonObject j;
    j["image_path"] = _path.c_str();
    int x1, y1, x2, y2;
    QJsonArray levelArray;
    for (int i = 0; i < selected_rois.size(); i++) {
        selected_rois.at(i).getCoords(&x1, &y1, &x2, &y2);

        QJsonObject jr;
        jr["x1"] = x1;
        jr["y1"] = y1;
        jr["x2"] = x2;
        jr["y2"] = y2;
        levelArray.append(jr);
    }
    j["coords"] = levelArray;

    QJsonDocument saveDoc(j);
    saveFile.write(saveDoc.toJson());
}