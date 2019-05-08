#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_H

#include <iostream>
#include <vector>
#include "Interpolation.h"

using namespace std;

class LinearInterpolation : public Interpolation
{
private:
    // f(x) = k[n] * x + b[n], n - count point
    vector<double> k; // angular coefficient
    vector<double> b; // additional constant

    void calculateRatios()
    {
        if (points.size() > 2)
        {

        }
    }

public:
    double getF(double x)
    {
        if (points.size() < 2)
        {
            throw Exception(ExceptionType::NO_POINTS);
        }
        else
        {   
            if (x < (points.begin())->first)
            {
                throw Exception(ExceptionType::BELOW_LOWER_VALUE);
            }
            if (x > (points.end())->first)
            {
                throw Exception(ExceptionType::ABOVE_UPPER_VALUE);
            }
            auto it = points.find(x);
            if (it != points.end())
            {
                return it->second;
            }
            else
            {

            }
        }
    }
};


#endif // LINEARINTERPOLATION_H
