#pragma once  // ifendef 
#include <iostream>

class Fraction
{
private:
	int ch, zn;
	void simplify();

public:
	Fraction(int ch = 0, int zn = 1); // конструктор по умолчанию
	
	Fraction operator+(const Fraction& b) const;  //ссылка это указатель который не позволяет вносить изменнеия в объект
	Fraction operator-(const Fraction& b) const;
	Fraction operator*(const Fraction& b) const;
	Fraction operator/(const Fraction& b) const;
		
	Fraction operator-() const;  // унарный минус a = -a 
	
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

	double get_decimal() const; // дробь в дестичный вид

	friend Fraction operator+(const int& a, const Fraction& b); // нет объекта с которым мы работаем , очень плохой метод, порядок не имеет значения
	friend Fraction operator-(const int& a, const Fraction& b);
	friend Fraction operator*(const int& a, const Fraction& b);
	friend Fraction operator/(const int& a, const Fraction& b);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& fr);
	~Fraction() {}; // пустой диструктор
};


