#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

//#define VAR_1

#ifdef VAR_1

enum class ExceptionType
{
    NO_POINTS,
    BELOW_LOWER_VALUE,
    ABOVE_UPPER_VALUE,
    WRONG_POINTS,
};

class Exception: public exception
{
private:
    string m_error;

public:
    Exception(std::string error)
        : m_error(error)
    {
    }

    Exception(ExceptionType error)
    {
        switch(error)
        {
        case ExceptionType::NO_POINTS:
            m_error = "for interpolation, the number of points must be more than one";
            break;

        case ExceptionType::BELOW_LOWER_VALUE:
            m_error = "out of interpolation range: below the lower interpolation value";
            break;

        case ExceptionType::ABOVE_UPPER_VALUE:
            m_error = "out of interpolation range: above the upper interpolation value";
            break;
        }
    }

    const char* what() const noexcept
    {
        return m_error.c_str();
    }
};

#else

class Exception: public exception
{
private:
    string m_error;

public:
    Exception(std::string error)
        : m_error(error)
    {
    }

    enum ExceptionType
    {
        NO_POINTS,
        LESS_FIRST_X,
        MORE_LAST_X,
        WRONG_SIZE,
    };

    Exception(ExceptionType error)
    {
        switch(error)
        {
        case NO_POINTS:
            m_error = "for interpolation, the number of points must be more than one";
            break;

        case LESS_FIRST_X:
            m_error = "out of interpolation range: below the lower interpolation value";
            break;

        case MORE_LAST_X:
            m_error = "out of interpolation range: above the upper interpolation value";
            break;

        case WRONG_SIZE:
            m_error = "x and y arrays of coordinate do not match";
            break;
        }
    }

    const char* what() const noexcept
    {
        return m_error.c_str();
    }
};

#endif

#endif // EXCEPTION_H
