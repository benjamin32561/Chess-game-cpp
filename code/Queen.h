#pragma once
#include "Bishop.h"
#include "Rook.h"

class Board;

class Queen : public Soldier
{
private:
	Bishop* r;
	Rook* t;
public:
	Queen(Point p, char tAc);
	~Queen();
	virtual bool move(Point& x, Board& b) override;
	virtual bool checkSolOnTheWay(Point& x, Board& b) override;
	Soldier* getRun() override;
	Soldier* getTower() override;
};

