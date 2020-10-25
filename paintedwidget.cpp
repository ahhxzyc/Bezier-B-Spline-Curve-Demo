#include "paintedwidget.h"

#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

#include <beziercurve.h>
#include <bsplinecurve.h>

PaintedWidget::PaintedWidget(int w, int h, float den) : width(w), height(h), curveDensity(den){
    resize(width, height);
    setWindowTitle(tr("Bezier & B-Spline Curve Demo"));
}


void PaintedWidget::paintEvent(QPaintEvent *event) {
    event->accept();

    QPainter painter(this);

    // Paint control points
    painter.setPen(QPen(Qt::blue, 10));
    for (const auto &p : points) {
        painter.drawPoint(p.x(), p.y());
    }

    // Paint the curve if there are enough points
    if (points.size() >= 3) {
        BezierCurve bezier(points, curveDensity);
        painter.setPen(QPen(Qt::red, 2));
        for (const auto &p : bezier.getCurve()) {
            painter.drawPoint(p.x(), p.y());
        }
    }

    if ((int)points.size() - 1 > 4) {
        BSplineCurve bspline(points, 4, curveDensity);
        painter.setPen(QPen(Qt::darkGreen, 2));
        for (const auto &p : bspline.getCurve()) {
            painter.drawPoint(p.x(), p.y());
        }
    }

}

void PaintedWidget::mousePressEvent(QMouseEvent *event) {
    event->accept();
    points.push_back({(float)event->x(), (float)event->y()});
    repaint();
}

