#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

/*enum class ExceptionType
{
    NO_POINTS,
    LESS_LOWER_BOUND,
    MORE_UPPER_BOUND,
    WRONG_SIZE,
};*/

class Exception: public exception
{
private:
    string m_error;

public:
    Exception(std::string error)
        : m_error(error)
    {}

    enum ExceptionType
    {
        NO_POINTS,
        LESS_LOWER_BOUND,
        MORE_UPPER_BOUND,
        WRONG_SIZE,
        NO_ENGINE,
    };

    Exception(ExceptionType error)
    {
        switch(error)
        {
        // case ExceptionType::NO_POINTS:
        case NO_POINTS:
            m_error = "for interpolation, the number of points must be more than one";
            break;

        // case ExceptionType::LESS_LOWER_BOUND:
        case LESS_LOWER_BOUND:
            m_error = "out of interpolation range: below the lower interpolation value";
            break;

        // case ExceptionType::MORE_UPPER_BOUND:
        case MORE_UPPER_BOUND:
            m_error = "out of interpolation range: above the upper interpolation value";
            break;

        // case ExceptionType::WRONG_SIZE:
        case WRONG_SIZE:
            m_error = "x and y arrays of coordinate do not match";
            break;

        // case ExceptionType::WRONG_SIZE:
        case NO_ENGINE:
            m_error = "no engine is installed in the test bench";
            break;
        }
    }

    const char* what() const noexcept
    {
        return m_error.c_str();
    }
};

#endif // EXCEPTION_H
