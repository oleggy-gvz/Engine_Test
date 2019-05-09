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
    double T_over; // overheating temperature
    double H_m; // coefficient of heating rate versus torque
    double H_v; // coefficient of heating rate versus speed of crankshaft rotation
    double C; // coefficient of cooling rates versus engine temperature and environment

    // motor parameters
    shared_ptr<Interpolation> M_V; // dependence of torque (M) on crankshaft rotation speed (V)
    double V; // current crankshaft rotation speed
    double I; // moment inertia

    double get_M()  { return M_V->getFunction(V); } // get current torque

    virtual double get_V_h() = 0; // get engine heating rate
    virtual double get_V_c(double t_envir) = 0; // get engine cooling rate
    virtual double get_a(); // get acceleration

public:
    void setTemperatureEngine(double t) { T_engine = t; }
    double getTemperatureEngine() { return T_engine; }
    bool getOverheatingEngine() { return T_engine > T_over; }

    virtual void Enable() = 0;
    virtual void Disable() = 0;
    virtual void SetRotationSpeed(double _V) = 0;
    virtual ~Engine() {}
};

#endif // ENGINE_H
