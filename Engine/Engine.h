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
    double T_engine; // current engine temperature
    double T_enver; // current temperature
    double T_over; // overheating temperature
    double H_m; // coefficient of heating rate versus torque
    double H_v; // coefficient of heating rate versus speed of crankshaft rotation
    double C; // coefficient of cooling rates versus engine temperature and environment

    // motor parameters
    shared_ptr<Interpolation> M_V; // dependence of torque (M) on crankshaft rotation speed (V)
    double V_current; // current crankshaft rotation speed
    double V_target;
    double I; // moment inertia

    double get_M() // get current torque
    {
        return M_V->getFunction(V_current);
    }

    virtual double get_V_h() = 0; // get engine heating rate
    virtual double get_V_c() = 0; // get engine cooling rate
    virtual double get_a() = 0; // get acceleration

    // temperature can be changed by environment, user cannot change
    void setTemperature(double _T)
    {
        if (!enable) // if engine was off, its temperature is equal envirolment temperature
        {
            T_engine = _T;
        }
    }

    // temperature can be changed by environment, user cannot change
    void setTemperatureEnvironment(double _T)
    {
        T_enver = _T;
    }

public:

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    bool isEnable()
    {
       return enable;
    }

    double getTemperature()
    {
        return T_engine;
    }

    bool getOverheatingStatus()
    {
        return T_engine > T_over;
    }

    void setRotationSpeed(double _V)
    {
        if (enable)
        {
            V_target = _V;
        }
    }

    double getRotationSpeed()
    {
        return V_current;
    }

    virtual void stepTime(double sec) = 0;

    // environment could only change the temperature engine
    friend void setTemperatureEnvironmentEngine(shared_ptr<Engine> engine, const Environment &envir);
    friend void setTemperatureEngine(shared_ptr<Engine> engine, const Environment &envir);
};

#endif // ENGINE_H
