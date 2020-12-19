#include <iostream>
#include <cmath>

namespace custom
{

class Modulus
{
public:
    Modulus(double value)
    : d_value(value)
    {
    }
    friend bool operator==(const Modulus& lhs, const Modulus& rhs)
    {
        return lhs.d_value == rhs.d_value;
    }
private:
    double d_value;
};

class ComplexNumber
{
public:
    ComplexNumber(double real, double imaginary)
    : d_real(real)
    , d_imaginary(imaginary)
    {
    }
    double modulus() const
    {
        double xSqr = d_real * d_real;
        double ySqr = d_imaginary * d_imaginary;
        return std::sqrt(xSqr + ySqr);
    }
    operator Modulus() const
    {
        return Modulus(modulus());
    }
private:
    double d_real;
    double d_imaginary;
};

} // namespace custom

int main()
{
    custom::Modulus m1(10);
    custom::Modulus m2(10);
    if (m1 == m2)
    {
        std::cout << "Modulus instances are same" << std::endl;
    }
    custom::ComplexNumber c1(3, 4);
    custom::ComplexNumber c2(4, 3);
    custom::Modulus m3 = c1;
    custom::Modulus m4 = c2;
    if (m3 == m4)
    {
        std::cout << "Complex number instances are same" << std::endl;
    }
    return 0;
}
