#ifndef ENGINE_H
#define ENGINE_H

#include <map>

using namespace std;

class Engine
{
private:
    double I; // moment inertia
    map<double, double> V_M; // x - rotation speed (V), y - torque (M)
    double T_over; // overheating temperature
    double H_m; // coefficient of heating rate versus torque


public:
    virtual ~Engine() = 0;
};

Engine::~Engine()
{}

#endif // ENGINE_H
