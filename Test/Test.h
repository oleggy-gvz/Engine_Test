#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Engine\Engine.h"

class TimeStep
{
public:
    static constexpr double SECOND_x_1 = 1;
    static constexpr double MILLISECOND_x_100 = 0.1;
    static constexpr double MILLISECOND_x_10 = 0.01;
    static constexpr double MILLISECOND_x_1 = 0.001;
    static constexpr double MICROSECOND_x_100 = 0.0001;
    static constexpr double MICROSECOND_x_10 = 0.00001;
    static constexpr double MICROSECOND_x_1 = 0.000001;
};

class Test
{
protected:
    shared_ptr<Engine> engine;

    double Time_test;
    double Time_curr;
    double Time_step;

public:
    Test() : Time_test(0), Time_curr(0), Time_step(TimeStep::MILLISECOND_x_100)
    {}

    void setEngine(shared_ptr<Engine> _engine)
    {
        engine = _engine;
    }

    void setTestingTime(double _T_test)
    {
        Time_test = _T_test;
    }

    void setTimeStep(double _T_step)
    {
        Time_step = _T_step;
    }

    double getCurrentTime()
    {
        return Time_curr;
    }

    virtual void Run() = 0;
    virtual void PrintResult() = 0;
};

#endif // TEST_H
