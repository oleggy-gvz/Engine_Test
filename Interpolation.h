#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <map>

using namespace std;

class Interpolation
{
protected:
    map<double, double> points;
    virtual void calculateRatios() = 0;

public:
    void add_point(double x, double y)
    {
        points[x] = y;
        if (points.size() > 2)
            calculateRatios();
    }
    virtual double getValue(double x) = 0;
};


#endif // INTERPOLATION_H
