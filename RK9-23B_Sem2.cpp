#include <iostream>

class Complex
{
private:
    double re, im;
public:
    Complex(double re = 0., double im = 0.);
    
    Complex operator+(const Complex& right)const;
    
    Complex operator-(const double& right)const;

    Complex& operator+=(const Complex& right);

    friend Complex operator*(const double& left, const Complex& right);

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex Complex:: operator+(const Complex& right)const
{
    return Complex(re + right.re, im + right.im);
}

Complex Complex:: operator-(const double& right)const
{
    return Complex(re - right, im);
}

Complex& Complex:: operator+=(const Complex& right)
{
    re += right.re;
    im += right.im;
    return *this;
}

Complex operator*(const double& left, const Complex& right)
{
    return Complex(left * right.re, left * right.im);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.re << '+' << c.im << 'i';
    return os;
}

int main()
{
    std::cout << "Hello World!\n";
}
