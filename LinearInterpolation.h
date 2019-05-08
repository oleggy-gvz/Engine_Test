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
            a_n.clear(); // clean old ratios
            b_n.clear();

            auto it_p1 = points.begin();
            auto it_p2 = it_p1;
            for (++it_p2; it_p2 != points.end(); ++it_p1, ++it_p2)
            {
                double a = (it_p2->second - it_p1->second) / (it_p2->first - it_p1->first);
                double b = it_p1->second - a * it_p1->first;
                a_n.push_back(a);
                b_n.push_back(b);
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
            auto it_first = points.begin();
            if (x < it_first->first)
            {
                throw Exception(Exception::LESS_FIRST_X);
            }
            auto it_last = points.rbegin();
            if (x > it_last->first)
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
                it = points.upper_bound(x);
                return it->first;
            }
        }
    }
};


#endif // LINEAR_INTERPOLATION_H
