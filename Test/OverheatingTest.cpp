#include "Test\OverheatingTest.h"

OverheatingTest::OverheatingTest(shared_ptr<Engine> _engine) :
    T_curr(0), Eps_T(AccuracyTemp::DECIMAL_PLACES_3), V_curr(0), V_step(1), Overheat(false), RunTest(false)
{
    setEngine(_engine);
}

OverheatingTest::OverheatingTest(shared_ptr<Engine> _engine, double _Time_test, double _Time_step, double _Eps_T, double _V_step) :
    T_curr(0), Eps_T(_Eps_T), V_curr(0), V_step(_V_step), Overheat(false), RunTest(false)
{
    setEngine(_engine);
    setTestingTime(_Time_test);
    setTimeStep(_Time_step);
}

bool OverheatingTest::checkOverheatStatus()
{
    Overheat = engine->getTemperature() > engine->getOverheatingTemperature();
    return Overheat;
}

bool OverheatingTest::getOverheatStatus()
{
    return Overheat;
}

bool OverheatingTest::checkTemperatureStability()
{
    double T_before = T_curr;
    T_curr = engine->getTemperature();
    return T_curr - T_before < Eps_T;
}

void OverheatingTest::readTemperatureEngine()
{
    T_curr = engine->getTemperature();
}

void OverheatingTest::stepTime()
{
    engine->stepTime(Time_step);
}

void OverheatingTest::setTemperatureAccuracy(double _Eps_T)
{
    Eps_T = _Eps_T;
}

void OverheatingTest::setRotationSpeedStep(double _V_step)
{
    V_step = _V_step;
}

void OverheatingTest::Run()
{
    RunTest = false;
    for (V_curr = 0; V_curr < engine->getMaxRotationSpeed(); V_curr += V_step)
    {
        engine->turnOn();
        // cout << "V current = " << V_curr << endl;
        engine->setRotationSpeed(V_curr);

        for (Time_curr = 0; Time_curr < Time_test; Time_curr += Time_step)
        {
            readTemperatureEngine();
            stepTime();
            if (checkOverheatStatus()) break;
            if (checkTemperatureStability()) break;
        }
        engine->turnOff();
        if (getOverheatStatus()) break;
    }
    RunTest = true;
}

void OverheatingTest::PrintResult()
{
    if (!RunTest)
    {
        cout << "there was no testing" << endl;
    }
    else
    {
        if (Overheat)
        {
            cout << "overheating speed, V (rad/sec) = " << V_curr << endl;
            cout << "overheating time, t (sec) = " << Time_curr << endl;
        }
        else
        {
            cout << "no overheating" << endl;
        }
    }
}
