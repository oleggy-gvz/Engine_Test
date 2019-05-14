#ifndef FUEL_ENGINES_H
#define FUEL_ENGINES_H

#include "EngineAssembly.h"
#include "Interpolation\LinearInterpolation.h"
#include "Engine\InternalCombustionEngine.h"

class FuelEngines : public EngineAssembly
{
    shared_ptr<Engine> CreateEngine(const string &type);
};

#endif // FUEL_ENGINES_H
