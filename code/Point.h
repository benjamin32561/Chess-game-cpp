#pragma once

class Point
{
public:
	Point(); 
	Point(const int x, const int y);
	~Point();
	Point& operator=(const Point& other);
	bool operator==(const Point& other) const;
	int getX();
	int getY();
protected:
	int _x;
	int _y;
};