#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H

#include <iostream>
#include <memory>
#include "Interpolation\Interpolation.h"

using namespace std;

class LinearInterpolation : public Interpolation
{
private:
    // f(x) = a[n] * x + b[n], n - count point
    vector<double> a; // angular coefficient
    vector<double> b; // additional constant
    map<double, unsigned int> segments;

    void calculateRatios()
    {
        if (points.size() > 1)
        {
            a.clear(); // clean old ratios
            b.clear();
            segments.clear();

            auto it_p1 = points.begin();
            auto it_p2 = it_p1;
            ++it_p2;
            for (unsigned int i = 0; it_p2 != points.end(); ++it_p1, ++it_p2, i++)
            {
                double a_cur = (it_p2->second - it_p1->second) / (it_p2->first - it_p1->first);
                double b_cur = it_p1->second - a_cur * it_p1->first;
                a.push_back(a_cur);
                b.push_back(b_cur);
                segments[it_p2->first] = i;
            }
        }
    }

public:
    LinearInterpolation(std::initializer_list<double> x, std::initializer_list<double> y)
    {
        setPoints(x, y);
    }

    LinearInterpolation(initializer_list<pair<double, double>> p)
    {
        setPoints(p);
    }

    double getFunction(double x)
    {
        if (points.size() < 2)
        {
            throw Exception(Exception::NO_POINTS);
        }
        else
        {   
            /*auto it_first = points.begin();
            if (x < it_first->first)*/
            if (x < points.begin()->first)
            {
                throw Exception(Exception::LESS_LOWER_BOUND);
            }
            /*auto it_last = points.rbegin();
            if (x > it_last->first)*/
            if (x > points.rbegin()->first)
            {
                throw Exception(Exception::MORE_UPPER_BOUND);
            }
            auto it = points.find(x);
            if (it != points.end()) // if the point is in table
            {
                return it->second;
            }
            else // else, calculate independently
            {
                auto it_n = segments.upper_bound(x);
                return a[it_n->second] * x + b[it_n->second];
            }
        }
    }
};

#endif // LINEAR_INTERPOLATION_H
