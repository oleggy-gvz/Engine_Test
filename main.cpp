#include <iostream>
#include "Interpolation\LinearInterpolation.h"
#include "Engine\InternalCombustionEngine.h"
#include "Environment\Environment.h"

using namespace std;

int main()
{
    Interpolation *V_M = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});
    //Interpolation *V_M = new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}};
    //cout << V_M->getFunction(0) << endl;

    Engine *engine = new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1);
    Environment env(20);
    env.setTemperature(30);
    env.setEngine(engine);

    engine->Enable();
    double t = engine->getTemperature();
    cout << t << endl;

    /*engine->DelayTime(120);
    cout << engine->getTemperatureEngine() << endl;*/

    return 0;
}
