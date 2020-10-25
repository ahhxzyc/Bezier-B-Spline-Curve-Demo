#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <vector>
#include <QPointF>

class BezierCurve
{
public:
    BezierCurve(const std::vector<QPointF> &points, float den);

    const std::vector<QPointF>& getCurve() const {return curve;}

private:
    std::vector<QPointF> curve;
    float density;

    void solve(const std::vector<QPointF> &points);
    int comb(int n, int i) const;
    float bernstein(float t, int n, int i) const;
};

#endif // BEZIERCURVE_H
