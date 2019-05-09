#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <map>
#include <vector>
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

    void setPoints(std::initializer_list<double> x, std::initializer_list<double> y)
    {
        if (x.size() != y.size())
            throw Exception(Exception::WRONG_POINTS);

        points.clear();
        auto it_x = x.begin();
        auto it_y = y.begin();
        for (; it_x != x.end(); ++it_x, ++it_y)
        {
            points[*it_x] = *it_y;
        }
        calculateRatios();
    }

    virtual double getFunction(double x) = 0;
};


#endif // INTERPOLATION_H
