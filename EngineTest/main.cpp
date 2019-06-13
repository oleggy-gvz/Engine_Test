#include "Environment\Environment.h"
#include "TestStand\SearchTests.h"
#include "EngineAssembly\FuelEngines.h"

using namespace std;

int main()
{
    shared_ptr<EngineAssembly> engine_assembly(new FuelEngines());
    shared_ptr<Engine> engine;

    engine= engine_assembly->GetEngine("Basic Internal Combustion Engine");
    //engine = engine_assembly->GetEngine("Basic Internal Combustion Engine with Cubic Spline");

    Environment envir(20); // default temperature of environment is 20C
    envir.setEngine(engine); // engine temperature will be equal to the temperature of environment

    // set other temperature environment
    double temp;
    cout << "environment temperature (C) = ";
    cin >> temp;
    envir.setTemperature(temp); // engine temperature will also change
    cout << endl;

    cout << "environment temperature is " << envir.getTemperature() << " C" << endl;
    shared_ptr<TestStand> test_stend(new SearchTests());
    test_stend->SetEngine(engine);

    test_stend->GetTest("Overheating Speed Test");

    system("pause");

    return 0;
}

