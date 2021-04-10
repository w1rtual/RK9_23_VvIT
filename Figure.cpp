#include <iostream>
#include <cmath>
#define M_PI  3.141592653589793284626433832795

class Figure {
private:
	double x, y;
	double angle;
public:
	Figure(const double X, const double Y, const double Angle)
	{
		x = X;
		y = Y;
		angle = Angle;
	}
	void replace(const double newX, const double newY, const double newAngle)
	{
		x = newX;
		y = newY;
		angle = newAngle;
	}
	void move(const double dx, const double dy)
	{
		x += dx;
		y += dy;
	}
	void rotate(const double dAngle)
	{
		angle += dAngle;
	}
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual ~Figure() {}
};
class Rectangle : public Figure {
private:
	double a, b;
public:
	Rectangle ( const double side_a, 
		  const double side_b,
		  const double center_x,
		  const double center_y,
		  const double rotation_angle = 0)
		   :Figure(center_x, center_y, rotation_angle), a(side_a), b(side_b) {}
	virtual double getPerimeter() const
	{
		return 2 * (a + b);
	}
	virtual double getArea() const
	{
		return a * b;
	}
	virtual ~Rectangle() {}
};
class Elipse : public Figure {
private:
	double a, b;
public:
	Elipse(const double side_a,
		const double side_b,
		const double center_x,
		const double center_y,
		const double rotation_angle = 0)
		:Figure(center_x, center_y, rotation_angle), a(side_a), b(side_b) {}
	virtual double getPerimeter() const
	{
		return (4 * (M_PI * a * b + (a - b) * (a - b)) / (a + b));
	}
	virtual double getArea() const
	{
		return M_PI * a * b;
	}
	virtual ~Elipse() {}
};
class Circle : public Elipse {
private:
	double a;
public:
	Circle(const double radius,
		const double center_x,
		const double center_y,
		const double rotation_angle = 0)
		:Elipse (radius, radius, center_x, center_y, rotation_angle), a(radius) {}
	virtual double getPerimeter() const
	{
		return M_PI * a * 2;
	}
	virtual double getArea() const
	{
		return M_PI * a * a;
	}
	virtual ~Circle() {}
};
class Circle_ : public Figure {
private:
	double a;
public:
	Circle_(const double radius,
		const double center_x,
		const double center_y,
		const double rotation_angle = 0)
		:Figure(center_x, center_y, rotation_angle), a(radius) {}
	virtual double getPerimeter() const
	{
		return M_PI * a * 2;
	}
	virtual double getArea() const
	{
		return M_PI * a * a;
	}
	virtual ~Circle_() {}
};
class Square : public Figure
{
private:
	Rectangle Rect;
public:
	Square(const double side_a,
		const double center_x,
		const double center_y,
		const double rotation_angle = 0) : Figure(center_x, center_y, rotation_angle), Rect(side_a, side_a, center_x, center_y, rotation_angle) {}

	virtual double getPerimeter() const
	{
		return Rect.getPerimeter();
	}
	virtual double getArea() const
	{
		return Rect.getArea();
	}
	virtual ~Square() {}
};
class Triangle_3_side : Figure
{
private:
	double a, b, c;
public:
	Triangle_3_side(const double side_a,
		const double side_b,
		const double side_c,
		const double center_x,
		const double center_y,
		const double rotation_angle = 0)
		:Figure(center_x, center_y, rotation_angle), a(side_a), b(side_b), c(side_c) {}
	virtual double getPerimeter() const
	{
		return (a + b + c);
	}
	virtual double getArea() const
	{
		return a * b * c;
	}
	virtual ~Triangle_3_side() {}
};
class Triangle_angle : Figure
{
private:
	double a, b, angle;
public:
	Triangle_angle(const double side_a,
		const double side_b,
		const double angle,
		const double center_x,
		const double center_y,
		const double rotation_angle = 0)
		:Figure(center_x, center_y, rotation_angle), a(side_a), b(side_b), angle(angle) {}
	virtual double getPerimeter() const
	{
		return;
	}
	virtual double getArea() const
	{
		return a * b * sin(angle);
	}
	virtual ~Triangle_angle() {}
};