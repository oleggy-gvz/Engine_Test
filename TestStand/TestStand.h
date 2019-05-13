#ifndef TEST_STAND_H
#define TEST_STAND_H

#include "Test\Test.h"
#include "Engine\Engine.h"
#include "Exception\Exception.h"
#include <memory>

class TestStand
{
protected:
    shared_ptr<Engine> engine;
    virtual shared_ptr<Test> CreateTest(const string &type) = 0;

public:
    shared_ptr<Test> GetTest(const string &type)
    {
        if (engine == nullptr)
        {
            throw Exception(Exception::NO_ENGINE);
        }

        shared_ptr<Test> test = CreateTest(type);

        test->Run();
        test->PrintResult();

        return test;
    }

    void SetEngine(shared_ptr<Engine> _engine)
    {
        engine = _engine;
    }
};

#endif // TEST_STAND_H
