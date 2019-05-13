#ifndef ENGINE_H
#define ENGINE_H

#include "Interpolation\Interpolation.h"
#include <memory>

class Environment;

class Engine
{
protected:
    bool enable;

    // temperature parameters
    double T_curr; // current engine temperature
    double T_enver; // temperature environment
    double T_over; // overheating temperature
    double H_m; // coefficient of heating rate versus torque
    double H_v; // coefficient of heating rate versus speed of crankshaft rotation
    double C; // coefficient of cooling rates versus engine temperature and environment

    // motor parameters
    shared_ptr<Interpolation> M_V; // dependence of torque (M) on crankshaft rotation speed (V)
    double V_curr; // current crankshaft rotation speed
    double V_target;
    double I; // moment inertia

    double get_M() // get current torque
    {
        return M_V->getFunction(V_curr);
    }

    virtual double get_V_h() = 0; // get engine heating rate
    virtual double get_V_c() = 0; // get engine cooling rate
    virtual double get_a() = 0; // get acceleration

    // protected - temperature can be changed by environment, user cannot change
    void setTemperature(double _T_curr)
    {
        if (!enable) // envirolment temperature is set only if engine is off
        {
            T_curr = _T_curr;
        }
    }

    // protected - temperature can be changed by environment, user cannot change
    void setTemperatureEnvironment(double _T)
    {
        T_enver = _T;
    }

public:

    Engine() : enable(false), T_curr(0), T_enver(0), T_over(0), H_m(0), H_v(0), C(0), M_V(nullptr), V_curr(0), V_target(0), I(0)
    {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    bool isEnable()
    {
       return enable;
    }

    double getTemperature()
    {
        return T_curr;
    }

    double getOverheatingTemperature()
    {
        return T_over;
    }

    void setRotationSpeed(double _V)
    {
        if (enable) // rotational speed is set only if engine is on
        {
            V_target = _V;
        }
    }

    double getRotationSpeed()
    {
        return V_curr;
    }

    double getMaxRotationSpeed()
    {
        return M_V->getUpperBoundArgument();
    }

    virtual void stepTime(double sec) = 0;

    // environment could only change the temperature engine
    friend void setTemperatureEnvironmentEngine(shared_ptr<Engine> engine, const Environment &envir);
    friend void setTemperatureEngine(shared_ptr<Engine> engine, const Environment &envir);
};

#endif // ENGINE_H
