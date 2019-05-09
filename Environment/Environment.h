#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Engine\Engine.h"
#include <memory>

class Environment
{
private:
    double T_enver; // environment temperature
    shared_ptr<Engine> engine;

public:
    Environment(double t_enver, Engine *_engine)
    {
        setTemperature(t_enver);
        setEngine(_engine);
    }

    Environment(double t_enver)
    {
        setTemperature(t_enver);
    }

    void setTemperature(double t_enver)
    {
        T_enver = t_enver;
        if (engine != nullptr)
        {
            engine->setTemperatureEnvironment(T_enver);
        }
    }

    double getTemperature()
    {
        return T_enver;
    }

    double setEngine(Engine *_engine)
    {
        engine = shared_ptr<Engine>(_engine);
        engine->setTemperature(T_enver);
        engine->setTemperatureEnvironment(T_enver);
    }
};

#endif // ENVIRONMENT_H
