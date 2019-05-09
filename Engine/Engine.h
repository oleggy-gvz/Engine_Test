#ifndef ENGINE_H
#define ENGINE_H

#include "Interpolation\Interpolation.h"
#include <memory>

class Engine
{
protected:
    double I; // moment inertia
    double V; // moment inertia
    shared_ptr<Interpolation> V_M; // x - rotation speed (V), y - torque (M)
    double T_over; // overheating temperature
    double H_m; // coefficient of heating rate versus torque
    double H_v; // coefficient of heating rate versus speed of crankshaft rotation
    double C; // coefficient of cooling rates versus engine temperature and environment

    virtual double get_V_h(double m, double v) = 0; // heating rate
    virtual double get_V_c(double t_envir, double t_engine) = 0; // cooling rate
    virtual double get_a(double m); // acceleration

    double get_M(double V)
    {
        return V_M->getFunction(V);
    }

public:

    virtual void SetEnable() = 0;
    virtual void Enable() = 0;
};

#endif // ENGINE_H
