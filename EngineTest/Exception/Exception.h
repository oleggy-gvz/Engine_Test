#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class Exception: public exception
{
private:
    string m_error;

public:
    enum ExceptionType
    {
        NO_POINTS_LINEAR,
        NO_POINTS_CUBICSPLINE,
        LESS_LOWER_BOUND,
        MORE_UPPER_BOUND,
        WRONG_SIZE,
        NO_ENGINE,
        UNKNOWN_ENGINE,
        UNKNOWN_TEST,
    };

    Exception(std::string error);
    Exception(ExceptionType error);
    const char* what() const noexcept;
};

#endif // EXCEPTION_H
