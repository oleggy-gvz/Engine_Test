#ifndef SEARCH_TESTS_H
#define SEARCH_TESTS_H

#include "TestStand\TestStand.h"
#include "Test\OverheatingTest.h"

class SearchTests : public TestStand
{
    shared_ptr<Test> CreateTest(const string &type);
};

#endif // SEARCH_TESTS_H
