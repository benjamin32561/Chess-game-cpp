#include "Queen.h"



Queen::Queen(Point p, char tAc):
	Soldier(p, tAc)
{
	r = new Bishop(p, tAc);
	t = new Rook(p, tAc);
}

Queen::~Queen()
{
}

bool Queen::move(Point& x, Board& b)
{
	if (t->move(x, b))
	{
		return true;
	}
	else if (r->move(x, b))
	{
		return true;
	}
	return false;
}

bool Queen::checkSolOnTheWay(Point& x, Board& b)
{
	return true;//the checking of soldiers on the way in the queen is already in the move method so i dont need this method to do something
}

Soldier* Queen::getRun()
{
	return this->r;
}

Soldier* Queen::getTower()
{
	return this->t;
}
