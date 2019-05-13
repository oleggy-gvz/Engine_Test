#ifndef INTERNAL_COMBUSTION_ENGINE_H
#define INTERNAL_COMBUSTION_ENGINE_H

#include "Engine\Engine.h"

class InternalCombustionEngine : public Engine
{
    double get_V_h(); // heating rate
    double get_V_c(); // cooling rate
    double get_a(); // acceleration

public:
    InternalCombustionEngine(double _I, Interpolation *_M_V, double _T_over, double _H_m, double _H_v, double _C);
    void turnOn();
    void turnOff();
    void stepTime(double sec);
};

#endif // INTERNAL_COMBUSTION_ENGINE_H
