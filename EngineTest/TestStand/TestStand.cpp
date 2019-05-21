#include "TestStand.h"

shared_ptr<Test> TestStand::GetTest(const string &type)
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

void TestStand::SetEngine(shared_ptr<Engine> _engine)
{
    engine = _engine;
}
