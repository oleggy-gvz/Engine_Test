#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Engine\Engine.h"

class Test
{
protected:
    shared_ptr<Engine> engine;

public:
    void setEngine(Engine *_engine)
    {
        engine = shared_ptr<Engine>(_engine);
    }

    virtual void Run() = 0;
};

#endif // TEST_H
