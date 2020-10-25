#include "bsplinecurve.h"

#include <QDebug>

BSplineCurve::BSplineCurve(const std::vector<QPointF> &points, int k_, float den) : k(k_), density(den)
{
    n = (int)points.size() - 1;
    // knot sequence {0,1,2,...,n+k}
    for (int i = 0; i <= n + k; i ++ ) {
        knots.push_back(i);
    }
    solve(points);
}


void BSplineCurve::solve(const std::vector<QPointF> &points) {
    float step = (knots[n] - knots[k]) / density;
    for (float t = knots[k]; t < knots[n]; t += step) {
        QPointF p(0.f, 0.f);
        for (int i = 0; i <= n; i ++ ) {
            p += points[i] * bsplineFunction(i, k, t);
        }
        curve.push_back(p);
    }

}


float BSplineCurve::bsplineFunction(int i, int order, float t) const {
    if (order == 1) {
        return (t >= knots[i] && t < knots[i + 1] ? 1 : 0);
    }
    return ((t - knots[i]) / (knots[i + order - 1] - knots[i])) * bsplineFunction(i, order - 1, t)
            + ((knots[i + order] - t) / (knots[i + order] - knots[i + 1])) * bsplineFunction(i + 1, order - 1, t);
}
