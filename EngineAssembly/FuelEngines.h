#ifndef FUEL_ENGINES_H
#define FUEL_ENGINES_H

#include "EngineAssembly\EngineAssembly.h"
#include "Interpolation\LinearInterpolation.h"
#include "Engine\InternalCombustionEngine.h"

class FuelEngines : public EngineAssembly
{
    virtual shared_ptr<Engine> CreateEngine(const string &type)
    {
        shared_ptr<Engine> engine;

        Interpolation *V_M = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});
        // OR
        //Interpolation *V_M = new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}};

        if (type == "Basic Internal Combustion Engine") engine = shared_ptr<Engine>(new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1));
        // here you can add another type engine
        // ...

        return engine;
    }
};

#endif // FUEL_ENGINES_H
