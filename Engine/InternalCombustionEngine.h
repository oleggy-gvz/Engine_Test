#ifndef INTERNAL_COMBUSTION_ENGINE_H
#define INTERNAL_COMBUSTION_ENGINE_H

#include "Engine\Engine.h"

class InternalCombustionEngine : public Engine
{
private:
    double get_a(double m) // acceleration
    {
        return m / I;
    }

    double get_V_h(double m, double v) // heating rate
    {
        return m * H_m + v * v * H_v;
    }

    double get_V_c(double t_envir, double t_engine) // cooling rate
    {
        return C * (t_envir - t_engine);
    }

    double get_M(double V)
    {
        return 0;
    }

public:
    virtual void Enable() = 0;
};

#endif // INTERNAL_COMBUSTION_ENGINE_H
