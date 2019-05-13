#ifndef OVERHEATING_TEST_H
#define OVERHEATING_TEST_H

#include <iostream>
#include "Test\Test.h"

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
    double T_curr, Eps_T;
    double V_curr, V_step;
    bool Overheat;
    bool RunTest;

    bool checkOverheatStatus();
    bool getOverheatStatus();
    bool checkTemperatureStability();
    void readTemperatureEngine();
    void stepTime();

public:
    OverheatingTest(shared_ptr<Engine> _engine);
    OverheatingTest(shared_ptr<Engine> _engine, double _Time_test, double _Time_step, double _Eps_T, double _V_step = 1);

    void setTemperatureAccuracy(double _Eps_T);
    void setRotationSpeedStep(double _V_step);

    void Run();
    void PrintResult();
};

#endif // OVERHEATING_TEST_H
