#include "Soldier.h"

/*
this method is the c'tor of the class
input: point to set at, the cheracter of the soldier
output: non
*/
Soldier::Soldier(Point p, char tAc)
{
	this->_loc = p;
	this->_typeAndColor = tAc;
	this->_num_of_moves = 0;
}

Soldier::~Soldier()
{
	
}

Soldier::Soldier()
{
	this->_loc = Point();
	this->_typeAndColor = HASHTAG;
}

/*
this method returns the type and color of the soldier
input: non
output: char
*/
char Soldier::getTypeAndColor()
{
	return this == nullptr ? HASHTAG : this->_typeAndColor;
}

/*
this method returns the point of the soldier
input: non
output: Point&
*/
Point& Soldier::getPoint()
{
	return this->_loc;
}

/*
this method is an operator the '=' operator for the soldier class
input: other object from class Soldier
output: &to the object we coppied to
*/
Soldier& Soldier::operator=(const Soldier& other)
{
	if (this == &other)
	{
		return *this;
	}
	this->_loc = other._loc;
	this->_typeAndColor = other._typeAndColor;
	return *this;
}

/*
this method is increacing the number of moves a soldier has made
input: non
output: non
*/
void Soldier::incNumOfMoves()
{
	_num_of_moves++;
}

/*
this method is for the queen
*/
Soldier* Soldier::getRun()
{
	return nullptr;
}

/*
this method is for the queen
*/
Soldier* Soldier::getTower()
{
	return nullptr;
}

/*
this function checks the color of the pawn
input: non
output: 'w' if the pawn is white, 'b' if the pawn is black '#' otherwise
*/
char Soldier::getColor()
{
	if (this->getTypeAndColor() >= 'A' && this->getTypeAndColor() < 'a')
	{
		return WHITE;
	}
	else if (this->getTypeAndColor() > 'a')
	{
		return BLACK;
	}
	return HASHTAG;
}

