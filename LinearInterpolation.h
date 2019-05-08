#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H

#include <iostream>
#include <memory>
#include "Interpolation.h"
#include "Exception.h"

using namespace std;

class LinearInterpolation : public Interpolation
{
private:
    // f(x) = a[n] * x + b[n], n - count point
    vector<double> a; // angular coefficient
    vector<double> b; // additional constant
    map<double, unsigned int> segments;
    shared_ptr<vector<double>> x, y;

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
            for (int i = 0; it_p2 != points.end(); ++it_p1, ++it_p2, i++)
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
    LinearInterpolation(vector<double> *_x, vector<double> *_y)
        : x(_x), y(_y)
    {

    }

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
                auto it_index = segments.upper_bound(x);
                unsigned int n = it_index->second;
                return a[n] * x + b[n];
            }
        }
    }
};

#endif // LINEAR_INTERPOLATION_H
