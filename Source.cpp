#include "Fraction.h"

Fraction::Fraction(int ch, int zn)
{
	if (this->zn)
	{
	}
	this->ch = (zn > 0) ? ch : -ch;
	this->zn = (zn > 0) ? zn : -zn;
	simplify();
	
	/*if ((ch > 0 && zn > 0) || (ch < 0 && zn > 0))
	{
		this->ch = ch;
		this->zn = zn;
	}
	if ((ch > 0 && zn < 0) || (ch < 0 && zn < 0))
	{
		this->ch = -ch;
		this->zn = -zn;
	}
	
	if (ch == 0)
	{
		this->ch = 0;
		this->zn = 1;
		return;
	}
	
	simplify(); */
}

void Fraction::simplify()
{
	int a, b, r;
	if (abs(ch) > zn)
	{
		a = abs(ch);
		b = zn;
	}
	else
	{
		a = zn;
		b = abs(ch);
	}
	r = a % b;
	while (r > 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	ch = ch / b;
	zn = zn / b;
	/*int a = ch, b = zn;
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else b = b % a;
	}
	int t = a + b;
	ch = ch / t;
	zn = zn / t;*/
}

Fraction Fraction::operator+(const Fraction& b) const
{
	int ch = this->ch * b.zn + this->zn * b.ch;
	int zn = this->zn * b.zn;
	return	Fraction(ch, zn);
}
Fraction Fraction::operator-(const Fraction& b) const
{
	int ch = this->ch * b.zn - this->zn * b.ch;
	int zn = this->zn * b.zn;
	return Fraction(ch, zn);
}
Fraction Fraction::operator*(const Fraction& b) const
{
	int ch = this->ch * b.ch;
	int zn = this->zn * b.zn;
	return Fraction(ch, zn);
}
Fraction Fraction::operator/(const Fraction& b) const
{
	int ch = this->ch * b.zn;
	int zn = this->zn * b.ch;
	return Fraction(ch, zn);
}

Fraction Fraction::operator-() const
{
	int ch = this->ch * (-1);
	int zn = this->zn;
	return Fraction(ch, zn);
}

Fraction& Fraction::operator+=(const Fraction& b)
{
	*this = *this + b;
	return *this;
}
Fraction& Fraction::operator-=(const Fraction& b)
{
	*this = *this - b;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& b)
{
	*this = *this * b;
	return *this;;
}
Fraction& Fraction::operator/=(const Fraction& b)
{
	*this = *this / b;
	return *this;
}

bool Fraction::operator==(const Fraction& b) const
{
	return ch * b.zn == zn * b.ch;
}
bool Fraction::operator!=(const Fraction& b) const
{
	return ch * b.zn != zn * b.ch;
}
bool Fraction::operator>=(const Fraction& b) const
{
	return ch * b.zn >= zn * b.ch;
}
bool Fraction::operator<=(const Fraction& b) const
{
	return ch * b.zn <= zn * b.ch;
}
bool Fraction::operator>(const Fraction& b) const
{
	return ch * b.zn > zn * b.ch;
}
bool Fraction::operator<(const Fraction& b) const
{
	return ch * b.zn >= zn * b.ch;
}

double Fraction::get_decimal() const
{
	return ch / (double)zn;
}
Fraction operator+(const int& a, const Fraction& b)
{
	return b + a;
}
Fraction operator-(const int& a, const Fraction& b)
{
	return -b + a;
}
Fraction operator*(const int& a, const Fraction& b)
{
	return b * a;
}
Fraction operator/(const int& a, const Fraction& b)
{
	return Fraction(a) / b;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fr)
{
	os << fr.ch << "/" << fr.zn << std::endl;
	return os;
}