#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <memory>
#include "Engine\Engine.h"

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
        if (engine != nullptr) // if engine is placed environment
        {
            setTemperatureEnvironmentEngine(engine, *this);
        }
    }

    double getTemperature() const
    {
        return T_enver;
    }

    void setEngine(Engine *_engine)
    {
        engine = shared_ptr<Engine>(_engine);
        setTemperatureEnvironmentEngine(engine, *this);
        if (!engine->isEnable()) // if engine was off, its temperature is equal envirolment temperature
        {
            setTemperatureEngine(engine, *this);
        }
    }
};

// friend methods for engine, becouse environment could only change temperature engine
void setTemperatureEnvironmentEngine(shared_ptr<Engine> engine, const Environment &envir)
{
    engine->setTemperatureEnvironment(envir.getTemperature());
}

void setTemperatureEngine(shared_ptr<Engine> engine, const Environment &envir)
{
    engine->setTemperature(envir.getTemperature());
}

#endif // ENVIRONMENT_H


