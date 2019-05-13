#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Engine\Engine.h"

class TimeStep
{
public:
    static constexpr double _1_SECOND = 1;
    static constexpr double _100_MILLISECOND = 0.1;
    static constexpr double _10_MILLISECOND = 0.01;
    static constexpr double _1_MILLISECOND = 0.001;
    static constexpr double _100_MICROSECOND = 0.0001;
    static constexpr double _10_MICROSECOND = 0.00001;
    static constexpr double _1_MICROSECOND = 0.000001;
};

class Test
{
protected:
    shared_ptr<Engine> engine;
    double Time_step;
    double Time_test;
    double Time_curr;

public:
    Test() : Time_curr(0), Time_test(0), Time_step(TimeStep::_100_MILLISECOND)
    {}

    void setEngine(Engine *_engine)
    {
        engine = shared_ptr<Engine>(_engine);
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
