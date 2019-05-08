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
    // f(x) = a[n] * x + b[n], n - count point
    vector<double> a_n; // angular coefficient
    vector<double> b_n; // additional constant

    void calculateRatios()
    {
        if (points.size() > 1)
        {
            auto it_p1 = points.begin();
            auto it_p2 = it_p1;
            ++it_p2;

            // clean old ratios
            a_n.clear();
            b_n.clear();

            double b, k;
            for (int i = 0; it_p2 != points.end(); i++)
            {
                k = (it_p2->second - it_p1->second) / (it_p2->first - it_p1->first);
                b = it_p1->second - k * it_p1->first;
                a_n.push_back(k);
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
            auto it = points.begin();
            double less = it->first;
            if (x < it->first)
            {
                throw Exception(Exception::LESS_FIRST_X);
            }
            it = points.end();
            if (x > it->first)
            {
                throw Exception(Exception::MORE_LAST_X);
            }
            it = points.find(x);
            if (it != points.end())
            {
                return it->second;
            }
            else
            {
                it = points.upper_bound(x);
                return it->first;
            }
        }
    }
};


#endif // LINEAR_INTERPOLATION_H
