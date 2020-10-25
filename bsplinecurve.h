#ifndef BSPLINECURVE_H
#define BSPLINECURVE_H

#include <QPointF>
#include <vector>

class BSplineCurve
{
public:
    BSplineCurve(const std::vector<QPointF> &points, int k_, float den);

    const std::vector<QPointF>& getCurve() const {return curve;}

private:
    std::vector<QPointF> curve;
    std::vector<float> knots;
    int n;
    int k;
    float density;

    void solve(const std::vector<QPointF> &points);
    float bsplineFunction(int i, int order, float t) const ;
};

#endif // BSPLINECURVE_H
