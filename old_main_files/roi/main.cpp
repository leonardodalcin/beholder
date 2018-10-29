// local packages
#include "headers/roi/roi.hpp"
// libraries
#include <QApplication>
#include <QCommandLineParser>
#include <QFileDialog>
#include <QPixmap>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    roi _roi;

    QString fileName = QFileDialog::getOpenFileName(&_roi, QObject::tr("Open File"),
						    "/home",
						    QObject::tr("Images (*.pgm *.png *.xpm *.jpg)"));
    QPixmap pixmap(fileName);

    QFileInfo file_info(fileName);
    _roi.set_path(fileName.toStdString());
    _roi.set_dir(file_info.dir().path().toStdString());
    _roi.setPixmap(fileName);
    _roi.resize(pixmap.size());
    _roi.show();

    return a.exec();
}
