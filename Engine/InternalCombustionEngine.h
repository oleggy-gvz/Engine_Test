#ifndef INTERNAL_COMBUSTION_ENGINE_H
#define INTERNAL_COMBUSTION_ENGINE_H

#include "Engine\Engine.h"

class InternalCombustionEngine : public Engine
{
    double get_V_h() // heating rate
    {
        return get_M() * H_m + V_curr * V_curr * H_v;
    }

    double get_V_c() // cooling rate
    {
        return C * (T_enver - T_curr);
    }

    double get_a() // acceleration
    {
        return get_M() / I;
    }

public:
    InternalCombustionEngine(double _I, Interpolation *_M_V, double _T_over, double _H_m, double _H_v, double _C)
    {
        I = _I;
        M_V = shared_ptr<Interpolation>(_M_V);
        T_over = _T_over;
        H_m = _H_m;
        H_v = _H_v;
        C = _C;
        enable = false;
    }

    void turnOn()
    {
        enable = true;
        setRotationSpeed(0);
    }

    void turnOff()
    {
        enable = false;
        V_curr = 0; // allow the engine rotation speed to be instantly drops momentum
        V_target = 0;
        setTemperature(T_enver); // allow the engine temperature to be instantly equal envirolment temperature
    }

    void stepTime(double sec)
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
};

#endif // INTERNAL_COMBUSTION_ENGINE_H
