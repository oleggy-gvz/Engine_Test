#ifndef SEARCH_TESTS_H
#define SEARCH_TESTS_H

#include "TestStand\TestStand.h"
#include "Test\OverheatingTest.h"

class SearchTests : public TestStand
{
    virtual shared_ptr<Test> CreateTest(const string &type)
    {
        shared_ptr<Test> test;

        if (type == "Overheating Speed Test") test = shared_ptr<Test>(new OverheatingTest(engine, 60*5, TimeStep::MILLISECOND_x_10, AccuracyTemp::DECIMAL_PLACES_7, 1));
        // here you can add another test
        // ...

        return test;
    }
};

#endif // SEARCH_TESTS_H
