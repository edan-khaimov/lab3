#ifndef ABS_H
#define ABS_H

#include "Complex.h"

template <typename T>
double abs(const T& value)
{
    return (value < 0) ? -value : value;
}

template <>
double abs<Complex>(const Complex& value)
{
    return value.Abs();
}

#endif
