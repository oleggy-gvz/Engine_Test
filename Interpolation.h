#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <map>
#include <vector>

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
    virtual double getFunction(double x) = 0;
};


#endif // INTERPOLATION_H
