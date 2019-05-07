#ifndef ENGINE_H
#define ENGINE_H

#include "Interpolation.h"

class Engine
{
private:
    double I; // moment inertia
    Interpolation *V_M; // x - rotation speed (V), y - torque (M)
    double T_over; // overheating temperature
    double H_m; // coefficient of heating rate versus torque
    double H_v; // coefficient of heating rate versus speed of crankshaft rotation
    double C; // coefficient of cooling rates versus engine temperature and environment

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
    void Enable()
    {

    }
};

#endif // ENGINE_H
