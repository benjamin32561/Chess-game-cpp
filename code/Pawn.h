#pragma once
#include "Soldier.h"

class Pawn : public Soldier
{
public: 
	Pawn(Point p, char tAc);
	~Pawn();
	bool move(Point& x, Board& b) override;
	bool checkSolOnTheWay(Point& x, Board& b) override;
};

