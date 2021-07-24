#pragma once
#include "Soldier.h"

class Rook : virtual public Soldier
{
public:
	Rook(Point p, char tAc);
	~Rook();
	virtual bool move(Point& x, Board& b) override;
	virtual bool checkSolOnTheWay(Point& x, Board& b) override;
};

