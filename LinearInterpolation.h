#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H

#include <iostream>
#include <vector>
#include "Interpolation.h"
#include "Exception.h"

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
            throw Exception(Exception::NO_POINTS);
        }
        else
        {   
            if (x < (points.begin())->first)
            {
                throw Exception(Exception::LESS_FIRST_X);
            }
            if (x > (points.end())->first)
            {
                throw Exception(Exception::MORE_LAST_X);
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


#endif // LINEAR_INTERPOLATION_H
