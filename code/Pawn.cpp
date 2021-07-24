#include "Pawn.h"

Pawn::Pawn(Point p, char tAc) : 
	Soldier(p, tAc)
{
}

Pawn::~Pawn()
{

}

bool Pawn::move(Point& x, Board& b)
{
	Point* p;
	char solInNewLoc;
	int flag = 0, yDir = 0, xChange = 0, yChange = 0;
	yDir = 1;
	xChange = x.getX() - this->getPoint().getX();
	yChange = x.getY() - this->getPoint().getY();
	if (this->getTypeAndColor() > 'a')//black
	{
		yDir = -1;
	}
	if (_num_of_moves == 0 && yChange == 2 * yDir && !checkSolOnTheWay(x,b) && xChange == 0 )
	{
		return true;
	}
	p = new Point(this->getPoint().getX(), this->getPoint().getY() + 1* yDir);
	if (xChange == 0 && yChange == 1 * yDir && b.getSolInLoc(p) == HASHTAG)
	{
		return true;
	}
	else if (std::abs(xChange) == 1 && yChange == 1 * yDir)
	{
		p = new Point(this->getPoint().getX() + xChange, this->getPoint().getY() + yChange);
		solInNewLoc = b.getSolInLoc(p);
		if (this->getColor() == WHITE && solInNewLoc > 'a')
		{
			return true;
		}
		else if (this->getColor() == BLACK && solInNewLoc >= 'A' && solInNewLoc < 'a')
		{
			return true;
		}
	}
	return false;

}

bool Pawn::checkSolOnTheWay(Point& x, Board& b)
{
	int yDir = 0;
	Point* p;
	yDir = 1;
	if (this->getColor() == BLACK)//black player move
	{
		yDir = -1;
	}
	p = new Point(x.getX(), x.getY() - 1 * yDir);
	return (b.getSolInLoc(p) != HASHTAG);
}
