#include "Point.h"
#include <cstddef>

Point::Point()
{
	_x = NULL;
	_y = NULL;
}

/*
this method is a c'tor of the Point class
input: x value, y value
output: non
*/
Point::Point(const int x, const int y)
{
	_x = x;
	_y = y;
}

Point::~Point()
{
}

/*
this method is the operator '=' for the class Point
input: another Point class object
output: &to the object i coppied to
*/
Point& Point::operator=(const Point& other)
{
	if (this == &other)
	{
		return *this;
	}
	this->_x = other._x;
	this->_y = other._y;
	return *this;
}

/*
this method is the operator '=='
input: Point class object
output: bool - if the 2 objects have the same values
*/
bool Point::operator==(const Point& other) const
{
	if (this->_x == other._x && this->_y == other._y)
	{
		return true;
	}
	return false;
}

/*
this method gets the x value
input: non
output: int
*/
int Point::getX()
{
	return this->_x;
}

/*
this method gets the y value
input: non
output: int
*/
int Point::getY()
{
	return this->_y;
}
