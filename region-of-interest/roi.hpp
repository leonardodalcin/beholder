#pragma once
// libraries
#include <QLabel>
#include <QMenu>
#include <string>
#include <vector>

class roi : public QLabel {
    Q_OBJECT

   public:
    roi(QWidget *parent = nullptr);
    ~roi();

    void set_path(std::string p);
    void set_dir(std::string d);

   protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

   private:
    bool selectionStarted;
    QRect selectionRect;
    QMenu contextMenu;
    std::string _path;
    std::string _dir;
    std::vector<QRect> selected_rois;
   private slots:
    void save_slot();
    void add_slot();
    void remove_slot();
};
