#pragma once  // ifendef 
#include <iostream>

class Fraction
{
private:
	int ch, zn;
	void simplify();

public:
	Fraction(int ch = 0, int zn = 1); // ����������� �� ���������
	
	Fraction operator+(const Fraction& b) const;  //������ ��� ��������� ������� �� ��������� ������� ��������� � ������
	Fraction operator-(const Fraction& b) const;
	Fraction operator*(const Fraction& b) const;
	Fraction operator/(const Fraction& b) const;
		
	Fraction operator-() const;  // ������� ����� a = -a 
	
	Fraction& operator+=(const Fraction& b);
	Fraction& operator-=(const Fraction& b);
	Fraction& operator*=(const Fraction& b);
	Fraction& operator/=(const Fraction& b);

	bool operator==(const Fraction& b) const;
	bool operator!=(const Fraction& b) const;
	bool operator>=(const Fraction& b) const;
	bool operator<=(const Fraction& b) const;
	bool operator>(const Fraction& b) const;
	bool operator<(const Fraction& b) const;

	double get_decimal() const; // ����� � ��������� ���

	friend Fraction operator+(const int& a, const Fraction& b); // ��� ������� � ������� �� �������� , ����� ������ �����, ������� �� ����� ��������
	friend Fraction operator-(const int& a, const Fraction& b);
	friend Fraction operator*(const int& a, const Fraction& b);
	friend Fraction operator/(const int& a, const Fraction& b);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& fr);
	~Fraction() {}; // ������ ����������
};


