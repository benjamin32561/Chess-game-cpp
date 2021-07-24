#pragma once
#include "Soldier.h"

class King : public Soldier
{
public:
	King(Point p, char tAc);
	~King();
	bool move(Point& x, Board& b) override;
	bool checkSolOnTheWay(Point& x, Board& b) override;
};
