#pragma once
#include "Soldier.h"

class Knight : public Soldier
{
public:
	Knight(Point p, char tAc);
	~Knight();
	bool move(Point& x, Board& b) override;
	bool checkSolOnTheWay(Point& x, Board& b) override;
};


