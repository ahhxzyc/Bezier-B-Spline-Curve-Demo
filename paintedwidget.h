#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>

#include <vector>
#include <QPointF>

class PaintedWidget : public QWidget
{
private:
    int width;
    int height;
    float curveDensity;
    std::vector<QPointF> points;

public:
    PaintedWidget(int w, int h, float den);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
};




#endif // PAINTEDWIDGET_H
