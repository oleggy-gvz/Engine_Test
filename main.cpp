#include "Interpolation\LinearInterpolation.h"
#include "Engine\InternalCombustionEngine.h"
#include "Environment\Environment.h"
#include "TestStand\OverheatingTest.h"

using namespace std;

int main()
{
    Interpolation *V_M = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});
    //Interpolation *V_M = new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}};

    Engine *engine = new InternalCombustionEngine(10, V_M, 110, 0.01, 0.0001, 0.1);

    Environment envir(20);
    envir.setEngine(engine); // put the engine on

    double temp = 20;
    envir.setTemperature(temp); // set temperature

    // testing
    Test *test = new OverheatingTest(engine, 60*5, TimeStep::_100_MILLISECOND, AccuracyTemp::DECIMAL_PLACES_7, 1);
    test->Run();
    test->PrintResult();

    return 0;
}

