#pragma once
#include "mainFunctions.h"

/*
this function is the function that convertes the entered string into 2 points
input: 2 points & and a string
output: non
*/
void string2TwoPoint(Point& p1, Point& p2, const std::string s)
{
	p1 = Point(s[0] - 'a', (int)(s[1] - '1'));
	p2 = Point(s[2] - 'a', (int)(s[3] - '1'));
}
