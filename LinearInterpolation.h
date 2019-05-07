#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_H

#include "Interpolation.h"

class LightsCommand : public Interpolation
{
private:
    void calculateRatios()
    {

    }

public:
    double getValue(double x)
    {
        if (points.size() > 2)
        {

        }
        else
        {
            throw "must be entered points more than one";
        }
    }
};


#endif // LINEARINTERPOLATION_H
