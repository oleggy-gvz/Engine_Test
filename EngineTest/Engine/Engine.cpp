#include "Engine.h"

Engine::Engine() : enable(false), T_curr(0), T_enver(0), T_over(0), H_m(0), H_v(0), C(0), M_V(nullptr), V_curr(0), V_target(0), I(0)
{}

double Engine::get_M() // get current torque
{
    return M_V->getFunction(V_curr);
}

// protected - temperature can be changed by environment, user cannot change
void Engine::setTemperature(double _T_curr)
{
    if (!enable) // envirolment temperature is set only if engine is off
    {
        T_curr = _T_curr;
    }
}

// protected - temperature can be changed by environment, user cannot change
void Engine::setTemperatureEnvironment(double _T_enver)
{
    T_enver = _T_enver;
}

bool Engine::isEnable()
{
    return enable;
}

double Engine::getTemperature()
{
    return T_curr;
}

double Engine::getOverheatingTemperature()
{
    return T_over;
}

void Engine::setRotationSpeed(double _V)
{
    if (enable) // rotational speed is set only if engine is on
    {
        V_target = _V;
    }
}

double Engine::getRotationSpeed()
{
    return V_curr;
}

double Engine::getMaxRotationSpeed()
{
    return M_V->getUpperBoundArgument();
}
