#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Engine\Engine.h"

class Environment
{
private:
    double T_enver; // environment temperature
    shared_ptr<Engine> engine;

public:
    Environment(double _T_enver);
    Environment(double _T_enver, shared_ptr<Engine> _engine);
    void setTemperature(double t_enver);
    double getTemperature() const;
    void setEngine(shared_ptr<Engine> _engine);
};

#endif // ENVIRONMENT_H
