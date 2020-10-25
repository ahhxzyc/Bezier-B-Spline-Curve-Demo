#include "beziercurve.h"

#include <cmath>
#include <QDebug>

BezierCurve::BezierCurve(const std::vector<QPointF> &points, float den) : density(den)
{
    solve(points);
}


void BezierCurve::solve(const std::vector<QPointF> &points) {
    float step = 1.f / density;
    int n = points.size() - 1;
    for (float t = 0.f; t < 1.f; t += step) {
        QPointF p{0.f, 0.f};
        for (int i = 0; i <= n; i ++ ) {
            p = p + points[i] * bernstein(t, n, i);
        }
/*
        float bsum = 0.f;
        for (int i = 0; i <= n; i ++ ) bsum += bernstein(t, n, i);
        qDebug() << "bernstein sum(" << t << "," << n << "): " << bsum;
*/
        curve.push_back(p);
    }
}

float BezierCurve::bernstein(float t, int n, int i) const {
    return comb(n, i) * powf(t, i) * powf(1 - t, n - i);
}

int BezierCurve::comb(int n, int i) const {
    if (i > n / 2) i = n - i;
    int result = 1;
    int k = 1;
    for (int j = n; j > n - i; j -- ) {
        result *= j;
        while (result % k == 0 && k <= i) result /= k ++ ;
    }
    return result;
}
