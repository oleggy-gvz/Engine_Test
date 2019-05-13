#include "Exception\Exception.h"

Exception::Exception(std::string error)
    : m_error(error)
{}

Exception::Exception(ExceptionType error)
{
    switch(error)
    {
    case NO_POINTS:
        m_error = "for interpolation, the number of points must be more than one";
        break;

    case LESS_LOWER_BOUND:
        m_error = "out of interpolation range: below the lower interpolation value";
        break;

    case MORE_UPPER_BOUND:
        m_error = "out of interpolation range: above the upper interpolation value";
        break;

    case WRONG_SIZE:
        m_error = "x and y arrays of coordinate do not match";
        break;

    case NO_ENGINE:
        m_error = "no engine is installed in the test bench";
        break;

    case UNKNOWN_ENGINE:
        m_error = "unknown engine type selected";
        break;

    case UNKNOWN_TEST:
        m_error = "unknown test type selected";
        break;
    }
}

const char* Exception::what() const noexcept
{
    return m_error.c_str();
}
