#pragma once
// libraries
#include <QLabel>
#include <QMenu>

class roi : public QLabel {
    Q_OBJECT

   public:
    roi(QWidget *parent = nullptr);
    ~roi();

   protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

   private:
    bool selectionStarted;
    QRect selectionRect;
    QMenu contextMenu;
   private slots:
    void saveSlot();
};
