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
    vector<double> k_n; // angular coefficient
    vector<double> b_n; // additional constant

    void calculateRatios()
    {
        if (points.size() > 1)
        {
            auto it_p1 = points.begin();
            auto it_p2 = it_p1;
            ++it_p2;

            k_n.clear(); // clean old
            b_n.clear(); // clean old
            double b, k;
            for (int i = 0; it_p2 != points.end(); i++)
            {
                k = (it_p2->second - it_p1->second) / (it_p2->first - it_p1->first);
                b = it_p1->second - k * it_p1->first;
                k_n.push_back(k);
                b_n.push_back(b);
                ++it_p1;
                ++it_p2;
            }
        }
    }

public:
    double getFunction(double x)
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
