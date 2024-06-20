#ifndef ABS_H
#define ABS_H

#include "Complex.h"

template <typename T>
double Abs(const T& value)
{
    return (value < 0) ? -value : value;
}

template <>
double Abs<Complex>(const Complex& value)
{
    return value.Abs();
}

#endif
