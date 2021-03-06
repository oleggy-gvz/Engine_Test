#include "InternalCombustionEngine.h"

InternalCombustionEngine::InternalCombustionEngine(double _I, shared_ptr<Interpolation> _M_V, double _T_over, double _H_m, double _H_v, double _C)
 : Engine(_I, _M_V, _T_over, _H_m, _H_v, _C)
{}

double InternalCombustionEngine::get_V_h()
{
    return get_M() * H_m + V_curr * V_curr * H_v;
}

double InternalCombustionEngine::get_V_c()
{
    return C * (T_enver - T_curr);
}

double InternalCombustionEngine::get_a()
{
    return get_M() / I;
}

void InternalCombustionEngine::turnOn()
{
    enable = true;
    setRotationSpeed(0);
}

void InternalCombustionEngine::turnOff()
{
    enable = false;
    V_curr = 0; // allow the engine rotation speed to be instantly drops momentum
    V_target = 0;
    setTemperature(T_enver); // allow the engine temperature to be instantly equal envirolment temperature
}

void InternalCombustionEngine::stepTime(double sec)
{
    if (V_curr < V_target)
    {
        V_curr += get_a() * sec;
    }
    else
    {
        V_curr = V_target; // allow the engine rotation speed to be instantly drops momentum
    }
    T_curr += sec * get_V_h() + sec * get_V_c();
}
