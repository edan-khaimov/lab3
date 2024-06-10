#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>
class Complex
{
private:
    double Real;
    double Im;
public:
    Complex()
    {
        Real = 0;
        Im = 0;
    }

    Complex(double real, double im)
    {
        Real = real;
        Im = im;
    }

    Complex(const Complex &number)
    {
        Real = number.Real;
        Im = number.Im;
    }

    double GetRealPart() const
    {
        return Real;
    }

    double GetImPart() const
    {
        return Im;
    }

    Complex operator+(const Complex& number) const
    {
        return {Real + number.Real, Im + number.Im};
    }

    Complex operator-(const Complex& number) const
    {
        return {Real - number.Real, Im - number.Im};
    }

    Complex operator*(const Complex& number) const
    {
        return {Real * number.Real - Im * number.Im, Real * number.Im + Im * number.Real};
    }

    bool operator==(const Complex& number) const
    {
        return (Real == number.Real && Im == number.Im);
    }

    bool operator!=(const Complex& number) const
    {
        return (Real != number.Real || Im == number.Im);
    }

    Complex& operator=(const Complex &number)
    = default;

    friend std::istream &operator>>(std::istream &in, Complex &number)
    {
        std::cout << "Enter real part of complex number " << std::endl;
        in >> number.Real;
        std::cout << "Enter image part of complex number " << std::endl;
        in >> number.Im;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Complex &number)
    {
        if (number.Im < 0)
        {
            return out << "(" << number.Real << " - " << -number.Im << "i" << ")";
        }
        else
        {
            return out << "(" << number.Real << " + " << number.Im << "i" << ")";
        }
    }

    double Abs() const
    {
        return std::sqrt(Real * Real + Im * Im);
    }
};

#endif