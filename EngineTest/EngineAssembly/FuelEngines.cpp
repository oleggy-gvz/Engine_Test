#include "FuelEngines.h"

shared_ptr<Engine> FuelEngines::CreateEngine(const string &type)
{
    shared_ptr<Engine> engine;

    if (type == "Basic Internal Combustion Engine")
    {
        shared_ptr<Interpolation> V_M (new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0}));
        engine = shared_ptr<Engine>(new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1));
    }
    else if (type == "Basic Internal Combustion Engine with Cubic Spline")
    {
        shared_ptr<Interpolation> V_M (new CubicSplineInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0}));
        engine = shared_ptr<Engine>(new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1));
    }
    // here you can add another type engine ...
    /*else if (type == "...")
    {
    }*/
    else
    {
        throw Exception(Exception::UNKNOWN_ENGINE);
    }

    return engine;
}
