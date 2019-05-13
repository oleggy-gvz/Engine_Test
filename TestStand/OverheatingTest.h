#ifndef OVERHEATING_TEST_H
#define OVERHEATING_TEST_H

#include <iostream>
#include "TestStand\Test.h"

class AccuracyTemp
{
public:
    static constexpr double DECIMAL_PLACES_1 = 0.1;
    static constexpr double DECIMAL_PLACES_2 = 0.01;
    static constexpr double DECIMAL_PLACES_3 = 0.001;
    static constexpr double DECIMAL_PLACES_4 = 0.0001;
    static constexpr double DECIMAL_PLACES_5 = 0.00001;
    static constexpr double DECIMAL_PLACES_6 = 0.000001;
    static constexpr double DECIMAL_PLACES_7 = 0.0000001;
};

class OverheatingTest : public Test
{
private:
    double Eps_T, T_curr;
    double V_curr, V_step;
    bool Overheat;
    bool RunTest;

    bool checkOverheatStatus()
    {
        Overheat = engine->getTemperature() > engine->getOverheatingTemperature();
        return Overheat;
    }

    bool getOverheatStatus()
    {
        return Overheat;
    }

    bool checkTemperatureStability()
    {
        double T_before = T_curr;
        T_curr = engine->getTemperature();
        return T_curr - T_before < Eps_T;
    }

    void readTemperatureEngine()
    {
        T_curr = engine->getTemperature();
    }

    void stepTime()
    {
        engine->stepTime(Time_step);
    }

public:
    OverheatingTest(Engine *_engine) :
        Eps_T(AccuracyTemp::DECIMAL_PLACES_3), T_curr(0), V_curr(0), V_step(1), Overheat(false), RunTest(false)
    {
        setEngine(_engine);
    }

    OverheatingTest(Engine *_engine, double _Time_test, double _Time_step, double _Eps_T, double _V_step = 1) :
                Eps_T(_Eps_T), T_curr(0), V_curr(0), V_step(_V_step), Overheat(false), RunTest(false)
    {
        setEngine(_engine);
        setTestingTime(_Time_test);
        setTimeStep(_Time_step);
    }

    void setTemperatureAccuracy(double _Eps_T)
    {
        Eps_T = _Eps_T;
    }

    void setRotationSpeedStep(double _V_step)
    {
        V_step = _V_step;
    }

    void Run()
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

    void PrintResult()
    {
        if (!RunTest)
        {
            cout << "there was no testing" << endl;
        }
        else
        {
            if (Overheat)
            {
                cout << "rotation speed (rad/sec) = " << V_curr << endl;
                cout << "overheating time (sec) = " << Time_curr << endl;
            }
            else
            {
                cout << "no overheating" << endl;
            }
        }
    }
};

#endif // OVERHEATING_TEST_H
