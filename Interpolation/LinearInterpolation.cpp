#include "Interpolation\LinearInterpolation.h"

LinearInterpolation::LinearInterpolation(std::initializer_list<double> x, std::initializer_list<double> y)
{
    setPoints(x, y);
}

LinearInterpolation::LinearInterpolation(initializer_list<pair<double, double>> p)
{
    setPoints(p);
}

void LinearInterpolation::calculateRatios()
{
    if (points.size() > 1)
    {
        // clean old ratios
        a.clear(); // clean a[i]
        b.clear(); // clean b[i]
        segments.clear(); // clean segments[i]

        auto it_p1 = points.begin();
        auto it_p2 = it_p1;
        ++it_p2;
        double a_cur, b_cur;
        for (unsigned int i = 0; it_p2 != points.end(); ++it_p1, ++it_p2, i++)
        {
            a_cur = (it_p2->second - it_p1->second) / (it_p2->first - it_p1->first);
            b_cur = it_p1->second - a_cur * it_p1->first;
            a.push_back(a_cur); // a[i]
            b.push_back(b_cur); // b[i]
            segments[it_p2->first] = i; // segment[i]
        }
    }
}

double LinearInterpolation::getFunction(double x)
{
    if (points.size() < 2)
    {
        throw Exception(Exception::NO_POINTS);
    }
    else
    {
        if (x < points.begin()->first)
        {
            throw Exception(Exception::LESS_LOWER_BOUND);
        }
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
