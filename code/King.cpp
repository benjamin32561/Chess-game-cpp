#include "King.h"

King::King(Point p, char tAc):
	Soldier(p, tAc)
{
}

King::~King()
{

}

bool King::move(Point& x, Board& b)
{
	int arrayPosMve[8][2] = { {0, 1}, {1, 1}, {1, 0}, {-1, -1}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1} };
	for (int i = 0; i < 8; i++)
	{
		if (this->getPoint().getY() == x.getY() - arrayPosMve[i][1] && this->getPoint().getX() == x.getX() - arrayPosMve[i][0])
		{
			return true;
		}
	}
	return false;
}

bool King::checkSolOnTheWay(Point& x, Board& b)
{
	return false;
}
