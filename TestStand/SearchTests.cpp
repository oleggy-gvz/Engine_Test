#include "SearchTests.h"

shared_ptr<Test> SearchTests::CreateTest(const string &type)
{
    shared_ptr<Test> test;

    if (type == "Overheating Speed Test")
    {
        test = shared_ptr<Test>(new OverheatingTest(engine, 60*5, TimeStep::MILLISECOND_x_10, AccuracyTemp::DECIMAL_PLACES_7, 1));
    }
    // here you can add another test ...
    /*else if (type == "...")
    {
    }*/
    else
    {
        throw Exception(Exception::UNKNOWN_TEST);
    }

    return test;
}
