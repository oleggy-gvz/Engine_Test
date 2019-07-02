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
    double V_target; // target crankshaft rotation speed
    double I; // moment inertia

    // protected - temperature can be changed by environment, user cannot change
    void setTemperature(double _T_curr);
    void setTemperatureEnvironment(double _T_enver);

    double get_M(); // get current torque
    virtual double get_V_h() = 0; // get engine heating rate
    virtual double get_V_c() = 0; // get engine cooling rate
    virtual double get_a() = 0; // get acceleration

public:

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void stepTime(double sec) = 0;

    Engine();
    Engine(double _I, shared_ptr<Interpolation> _M_V, double _T_over, double _H_m, double _H_v, double _C);
    bool isEnable();
    double getTemperature();
    double getOverheatingTemperature();
    void setRotationSpeed(double _V);
    double getRotationSpeed();
    double getMaxRotationSpeed();

    // environment could only change the temperature engine
    friend void setTemperatureEnvironmentEngine(shared_ptr<Engine> engine, const Environment &envir);
    friend void setTemperatureEngine(shared_ptr<Engine> engine, const Environment &envir);
};

#endif // ENGINE_H
