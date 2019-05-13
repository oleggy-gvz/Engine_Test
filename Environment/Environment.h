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
    Environment(double _T_enver) : T_enver(_T_enver)
    {}

    Environment(double _T_enver, Engine *_engine) : T_enver(_T_enver)
    {
        setEngine(_engine);
    }

    void setTemperature(double t_enver)
    {
        T_enver = t_enver;
        if (engine != nullptr) // if engine is placed environment
        {
            setTemperatureEnvironmentEngine(engine, *this);
            setTemperatureEngine(engine, *this);
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
        setTemperatureEngine(engine, *this);
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


