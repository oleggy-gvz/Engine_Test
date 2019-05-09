#ifndef INTERNAL_COMBUSTION_ENGINE_H
#define INTERNAL_COMBUSTION_ENGINE_H

#include "Engine\Engine.h"

class InternalCombustionEngine : public Engine
{
    double get_V_h() // heating rate
    {
        return get_M() * H_m + V * V * H_v;
    }

    double get_V_c() // cooling rate
    {
        return C * (T_enver - T_engine);
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

    void Enable()
    {
        enable = true;
        SetRotationSpeed(0);
    }

    void Disable()
    {
        SetRotationSpeed(0);
        enable = false;
    }

    void SetRotationSpeed(double _V)
    {
        if (enable)
        {
            V = _V;
        }
    }
};

#endif // INTERNAL_COMBUSTION_ENGINE_H
