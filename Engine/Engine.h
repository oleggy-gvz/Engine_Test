#ifndef ENGINE_H
#define ENGINE_H

#include "Interpolation\Interpolation.h"
#include <memory>

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
    double V; // current crankshaft rotation speed
    double I; // moment inertia

    double get_M() // get current torque
    {
        return M_V->getFunction(V);
    }

    virtual double get_V_h() = 0; // get engine heating rate
    virtual double get_V_c() = 0; // get engine cooling rate
    virtual double get_a() = 0; // get acceleration

public:
    void setTemperature(double _T)
    {
        T_engine = _T;
    }

    void setTemperatureEnvironment(double _T)
    {
        T_enver = _T;
    }

    double getTemperature()
    {
        return T_engine;
    }

    bool getOverheatingStatus()
    {
        return T_engine > T_over;
    }

    virtual void Enable() = 0;
    virtual void Disable() = 0;
    virtual void SetRotationSpeed(double _V) = 0;

    void DelayTime(double sec)
    {
        T_engine += sec * get_V_h();
        T_engine += sec * get_V_c();
    }
};

#endif // ENGINE_H
