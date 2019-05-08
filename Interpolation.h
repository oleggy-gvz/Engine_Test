#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <map>
#include "Exception.h"

using namespace std;

class Interpolation
{
protected:
    map<double, double> points;
    virtual void calculateRatios() = 0;

public:
    void addPoint(double x, double y)
    {
        points[x] = y;
        calculateRatios();
    }
    virtual double getF(double x) = 0;
};


#endif // INTERPOLATION_H
