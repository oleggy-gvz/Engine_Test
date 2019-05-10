#include "Interpolation\LinearInterpolation.h"
#include "Engine\InternalCombustionEngine.h"
#include "Environment\Environment.h"
#include "TestStand\BasicTest.h"

using namespace std;

int main()
{
    Interpolation *V_M = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});
    //Interpolation *V_M = new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}};
    //cout << V_M->getFunction(0) << endl;
    Engine *engine = new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1);

    Environment envir(20);
    envir.setEngine(engine);
    envir.setTemperature(30);

    Test *test = new BasicTest(engine);
    test->Run();

    return 0;
}

