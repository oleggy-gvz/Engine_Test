#ifndef CUBIC_SPLINE_INTERPOLATION_H
#define CUBIC_SPLINE_INTERPOLATION_H

#include "..\Interpolation\Interpolation.h"

class CubicSplineInterpolation : public Interpolation
{
private:
    // f(x) = a[i] + b[i] * (x - x[i]) + c[i] * (x - x[i])^2 + d[i] * (x - x[i])^3 , i = 0,1..n-2, n - count points
    vector<double> a; // a[i], coefficient a
    vector<double> b; // b[i], coefficient b
    vector<double> c; // c[i], coefficient c
    vector<double> d; // d[i], coefficient d

    // segments[i], i = 0,1..n-2, for easy index (i) lookup
    map<double, unsigned int> segments; // upper bound (x2) of segment x1..x2 <-> index of segment

    void calculateRatios();

public:
    CubicSplineInterpolation(std::initializer_list<double> x, std::initializer_list<double> y);
    CubicSplineInterpolation(initializer_list<pair<double, double>> p);
    double getFunction(double x);
};

#endif // CUBIC_SPLINE_INTERPOLATION_H
