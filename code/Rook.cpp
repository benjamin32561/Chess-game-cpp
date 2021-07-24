#include "Rook.h"

Rook::Rook(Point p, char tAc):
	Soldier(p, tAc)
{
}

Rook::~Rook()
{
}

bool Rook::move(Point& x, Board& b)
{
	if ((x.getX() == this->getPoint().getX() || x.getY() == this->getPoint().getY()) && !checkSolOnTheWay(x, b))
	{
		return true;
	}
	return false;
}

bool Rook::checkSolOnTheWay(Point& x, Board& b)
{
	Point* p;
	int incX = 0, incY = 0, numOfBlocks = 0;
	if (x.getX() == this->getPoint().getX())
	{
		incY = 1;
		if (x.getY() < this->getPoint().getY())
		{
			incY = -1;
		}
		numOfBlocks = std::abs(x.getY() - this->getPoint().getY());
	}
	else if (x.getY() == this->getPoint().getY())
	{
		incX = 1;
		if (x.getX() < this->getPoint().getX())
		{
			incX = -1;
		}
		numOfBlocks = std::abs(x.getX() - this->getPoint().getX());
	}
	for (int i = 1; i < numOfBlocks; i++)
	{
		p = new Point(this->getPoint().getX() + i * incX, this->getPoint().getY() + i * incY);
		if (b.getSolInLoc(p) != HASHTAG)
		{
			return true;
		}
	}
	return false;
}
