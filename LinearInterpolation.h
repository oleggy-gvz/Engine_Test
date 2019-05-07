#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_H

#include <iostream>
#include <vector>
#include "Interpolation.h"

using namespace std;

class LinearInterpolation : public Interpolation
{
private:
    // y = f(x) = k[n] * x + b[n], n - count point
    vector<double> k; // angular coefficient
    vector<double> b; // additional constant

    void calculateRatios()
    {
        if (points.size() > 2)
        {

        }
    }

public:
    double getY(double x)
    {
        if (points.empty()) // size = 0
        {
            try
            {
                throw "no interpolation points";
            }
            catch (const char *exception)
            {
                cerr << exception << endl;
            }
        }
        else if (points.size() = 1) // size = 1
        {
            return (*points.begin()).second;
        }
        else // size > 1
        {
            auto it = points.find(x);
            if (it != points.end())
            {
                return (*it).second;
            }
            else
            {
                return -1;
            }
        }
    }
};


#endif // LINEARINTERPOLATION_H
