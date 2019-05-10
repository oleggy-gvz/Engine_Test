#ifndef BASIC_TEST_H
#define BASIC_TEST_H

#include <iostream>
#include "TestStand\Test.h"

class BasicTest : public Test
{
public:
    BasicTest(Engine *_engine)
    {
        setEngine(_engine);
    }

    virtual void Run()
    {
        engine->turnOn();
        engine->setRotationSpeed(10);

        unsigned int time_test = 240;
        double eps = 0.000001;

        double temp_cur, time_cur;
        double temp_last = engine->getTemperature();
        for (time_cur = 0; time_cur < time_test; time_cur++)
        {
            engine->timeStep(1);
            temp_cur = engine->getTemperature();
            if (temp_cur - temp_last < eps) break;
            temp_last = temp_cur;
        }

        engine->turnOff();

        cout << "time (sec) = " << time_cur << endl;
        cout << "temperature (C) = " << temp_cur << endl;
    }
};

#endif // BASIC_TEST_H
