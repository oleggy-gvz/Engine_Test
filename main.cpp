#include <iostream>
#include "Interpolation\LinearInterpolation.h"
#include "Engine\InternalCombustionEngine.h"

using namespace std;

int main()
{
    Interpolation *V_M = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});
    //Interpolation *V_M = new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}};

    Engine *e = new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1);
    e->Enable();

    return 0;
}
