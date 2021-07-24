#pragma once
#include <iostream>
#include "Soldier.h"

#define THE_MATRIX 8
#define	WHITE 'w'
#define BLACK 'b'
#define HASHTAG '#'

class Soldier;

class Board
{
public:
	Board(std::string s);
	~Board();
	int checkMove(Point loc, Point newLoc, const char turn);
	void boardToString(char* toRet);
	bool checkChes(const char color);
	Point getKingLoc(const char color);
	void moveSol(Point loc, Point newLoc);
	char getSolInLoc(Point* loc);
	void printBoard();
protected:
	Soldier* _board[THE_MATRIX][THE_MATRIX];
};