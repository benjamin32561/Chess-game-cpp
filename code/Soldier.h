#pragma once
#include "Point.h"
#include <iostream>
#include "Board.h"

class Board;

class Soldier
{
public:
	Soldier(Point p, char tAc);
	~Soldier();
	Soldier();
	/*
	this method is a pure virtual method that checks if the move can be done
	input: point to move the object to, the board to move the soldier on
	output: bool - if the player has been move true, false otherwise
	*/
	virtual bool move(Point& x, Board& b) = 0;
	/*
	this method is a pure virtual methods that checks if there are any soldiers on the way between the corrent soldier to the asked sqr
	input: the asked sqr, the board
	output: bool - if there is a soldoer between them rturns true, false otherwise
	*/
	virtual bool checkSolOnTheWay(Point& x, Board& b) = 0;
	char getTypeAndColor();
	Point& getPoint();
	Soldier& operator=(const Soldier& other);
	void incNumOfMoves();
	virtual Soldier* getRun();
	virtual Soldier* getTower();
	char getColor();
protected:
	char _typeAndColor;
	Point _loc;
	int _num_of_moves;
};