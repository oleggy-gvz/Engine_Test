#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <map>
#include <vector>
#include "Exception\Exception.h"

using namespace std;

class Interpolation
{
protected:
    map<double, double> points; // interpolation table
    virtual void calculateRatios() = 0;

public:
    void addPoint(double x, double y)
    {
        points[x] = y;
        calculateRatios();
    }

    void setPoints(initializer_list<double> x, initializer_list<double> y)
    {
        if (x.size() != y.size())
        {
            throw Exception(Exception::WRONG_SIZE);
        }

        points.clear();
        auto it_x = x.begin();
        auto it_y = y.begin();
        for (; it_x != x.end(); ++it_x, ++it_y)
        {
            points[*it_x] = *it_y;
        }
        calculateRatios();
    }

    void setPoints(initializer_list<pair<double, double>> p)
    {
        points.clear();
        for(const auto& item : p)
        {
            points[item.first] = item.second;
        }
        calculateRatios();
    }

    virtual double getFunction(double x) = 0;
};


#endif // INTERPOLATION_H
