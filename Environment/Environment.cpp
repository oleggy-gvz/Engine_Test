#include "Environment\Environment.h"

Environment::Environment(double _T_enver) : T_enver(_T_enver)
{}

Environment::Environment(double _T_enver, shared_ptr<Engine> _engine) : T_enver(_T_enver)
{
    setEngine(_engine);
}

void Environment::setTemperature(double t_enver)
{
    T_enver = t_enver;
    if (engine != nullptr) // if engine is placed environment
    {
        setTemperatureEnvironmentEngine(engine, *this);
        setTemperatureEngine(engine, *this);
    }
}

double Environment::getTemperature() const
{
    return T_enver;
}

void Environment::setEngine(shared_ptr<Engine> _engine)
{
    engine = _engine;
    setTemperatureEnvironmentEngine(engine, *this);
    setTemperatureEngine(engine, *this);
}

// friend methods for engine, becouse environment could only change temperature engine
// user cannot change temperature engine
void setTemperatureEnvironmentEngine(shared_ptr<Engine> engine, const Environment &envir)
{
    engine->setTemperatureEnvironment(envir.getTemperature());
}

void setTemperatureEngine(shared_ptr<Engine> engine, const Environment &envir)
{
    engine->setTemperature(envir.getTemperature());
}
