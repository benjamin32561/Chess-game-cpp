#include "Bishop.h"

Bishop::Bishop(Point p, char tAc):
	Soldier(p, tAc)
{

}

Bishop::~Bishop()
{

}

bool Bishop::move(Point& x, Board& b)
{
	int numOfBlocksY = 0, numOfBlocksX = 0;
	numOfBlocksY = x.getY() - this->getPoint().getY();
	numOfBlocksX = x.getX() - this->getPoint().getX();
	if (numOfBlocksY*1.0 / numOfBlocksX != 1 && numOfBlocksY * 1.0 / numOfBlocksX != -1)//the number he tried to move in x is diferrent from the one in y
	{
		return false;
	}
	return checkSolOnTheWay(x, b) ? false : true;
}

bool Bishop::checkSolOnTheWay(Point& x, Board& b)
{
	Point* p;
	int numOfBlocksY = 0, numOfBlocksX = 0, numToIncX = 0, numToIncY = 0;
	numOfBlocksY = x.getY() - this->getPoint().getY();
	numOfBlocksX = x.getX() - this->getPoint().getX();
	numToIncX = 1;
	numToIncY = 1;
	if (numOfBlocksY < 0)
	{
		numToIncY = -1;
	}
	if (numOfBlocksX < 0)
	{
		numToIncX = -1;
	}
	for (int i = 1; i < std::abs(numOfBlocksY); i++)
	{
		p = new Point(this->getPoint().getX() + numToIncX * i, this->getPoint().getY() + numToIncY * i);
		if (b.getSolInLoc(p) != HASHTAG)
		{
			return true;
		}
	}
	return false;
}
