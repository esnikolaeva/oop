#ifndef RHOMB_H
#define RHOMB_H
#include <iostream>
#include <cstdlib>
class Point {
public:
	double x, y;
	Point& operator=(const Point& right);
};
class Rhomb {
public:
	double Square();
	friend std::ostream& operator<<(std::ostream& os, const Rhomb& obj);
	friend std::istream& operator>>(std::istream& is, Rhomb& obj);
	Rhomb& operator=(const Rhomb& right);
	double diag1;
	double diag2;
	Point center;
};
#endif

