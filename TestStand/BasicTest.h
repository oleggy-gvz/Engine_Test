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
        engine->setRotationSpeed(50);

        unsigned int time_test = 40;
        double t_step = 0.1;
        double eps = 0.000001;
        double temp_before, temp_now = engine->getTemperature();

        for (double t = 0; t < time_test; t += t_step)
        {
            cout << "temp (C) = " << temp_now;
            cout << ",\tV (rad/sec) = " << engine->getRotationSpeed() << endl;

            engine->stepTime(t_step);

            temp_now = engine->getTemperature();
            /*if (temp_before - temp_now < eps) break;
            temp_before = temp_now;*/
        }

        engine->turnOff();

        cout << "temperature (C) = " << temp_now << endl;
    }
};

#endif // BASIC_TEST_H
