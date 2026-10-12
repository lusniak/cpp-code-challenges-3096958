#include "complex_num.h"

complex_num::complex_num(double r, double i)
{
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w)
{
    complex_num z;
    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w)
{
    complex_num z;
    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w)
{
    // z*w = (a+ib)*(c+id) = (ac-bd) + i(ad+bc)
    complex_num z;
    z.real = ((real*w.real) - (imaginary*w.imaginary));
    z.imaginary = ((real*w.imaginary) + (imaginary*w.real));
    return z;
}

complex_num complex_num::operator /(complex_num w)
{
    complex_num z;
    //z/w = (a+ib)/(c+id) = ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
    return z;
}

void complex_num::print(std::ostream &os)
{
    std::cout<< real << " " << imaginary;
}