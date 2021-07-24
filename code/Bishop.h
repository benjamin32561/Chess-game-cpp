#pragma once
#include "Soldier.h"

class Bishop : virtual public Soldier
{
public:
	Bishop(Point p, char tAc);
	~Bishop();
	virtual bool move(Point& x, Board& b) override;
	virtual bool checkSolOnTheWay(Point& x, Board& b) override;
};

