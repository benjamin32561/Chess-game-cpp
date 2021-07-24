#include "Knight.h"

Knight::Knight(Point p, char tAc):
	Soldier(p, tAc)
{
}

Knight::~Knight()
{
}

bool Knight::move(Point& x, Board& b)
{
	int yH = 0, xH = 0;
	xH = std::abs(x.getX() - this->getPoint().getX());
	yH = std::abs(x.getY() - this->getPoint().getY());
	return ((xH == 2 && yH == 1) || (xH == 1 && yH == 2));
}

bool Knight::checkSolOnTheWay(Point& x, Board& b)
{
	return false;
}
