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
    double Eps_T;
    double V_step;

public:
    OverheatingTest(Engine *_engine) : Eps_T(AccuracyTemp::DECIMAL_PLACES_3), V_step(1)
    {
        setEngine(_engine);
    }

    OverheatingTest(Engine *_engine, double _T_test, double _T_step, double _Eps_T, double _V_step)
    {
        setEngine(_engine);
        setTestingTime(_T_test);
        setTimeStep(_T_step);
        setTemperatureAccuracy(_Eps_T);
        setRotationSpeedStep(_V_step);
    }

    void setTemperatureAccuracy(double _Eps_T)
    {
        Eps_T = _Eps_T;
    }

    void setRotationSpeedStep(double _V_step)
    {
        V_step = _V_step;
    }

    virtual void Run()
    {
        double V, T_before, T_now;
        bool over = false;

        for (V = 0; V < engine->getMaxRotationSpeed(); V += V_step)
        {
            engine->turnOn();
            //cout << "V current = " << V << endl;
            engine->setRotationSpeed(V);
            T_now = engine->getTemperature();
            for (Time_curr = 0; Time_curr < Time_test; Time_curr += Time_step)
            {
                engine->stepTime(Time_step);
                if (T_now > engine->getOverheatingTemperature())
                {
                    over = true;
                    break;
                }
                T_before = T_now;
                T_now = engine->getTemperature();
                if (T_now - T_before < Eps_T) continue;
            }
            engine->turnOff();
            if (over) break;
        }

        if (over)
        {
            cout << "rotation speed (rad/sec) = " << V << endl;
            cout << "overheating time (sec) = " << Time_curr << endl;
        }
        else
        {
            cout << "no overheating" << endl;
        }
    }
};

#endif // OVERHEATING_TEST_H
