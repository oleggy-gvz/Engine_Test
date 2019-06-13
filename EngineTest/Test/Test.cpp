#include "Test.h"

Test::Test() : Time_test(0), Time_curr(0), Time_step(TimeStep::MILLISECOND_x_100)
{
    setNewTest();
}

void Test::setEngine(shared_ptr<Engine> _engine)
{
    engine = _engine;
}

void Test::setTestingTime(double _T_test)
{
    Time_test = _T_test;
}

void Test::setTimeStep(double _T_step)
{
    Time_step = _T_step;
}

void Test::setNewTest()
{
    isTested = false;
}

void Test::setCompletedTest()
{
    isTested = true;
}

bool Test::getCompletedTest()
{
    return isTested;
}

double Test::getCurrentTime()
{
    return Time_curr;
}
