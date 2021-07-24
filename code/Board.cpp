#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"

/*
this method is the c'tor of the board object
input: a string to make the soldiers from
output: non
*/
Board::Board(std::string s)
{
	int c = 0;
	Soldier* sol = nullptr;
	for (int i = 0; i < THE_MATRIX; i++)
	{
		for (int j = 0; j < THE_MATRIX; j++)
		{
			if (s[c] == 'r' || s[c] == 'R')
			{
				sol = new Rook(Point(j, i), s[c]);
			}
			else if (s[c] == 'k' || s[c] == 'K')
			{
				sol = new King(Point(j, i), s[c]);
			}
			else if (s[c] == 'n' || s[c] == 'N')
			{
				sol = new Knight(Point(j, i), s[c]);
			}
			else if (s[c] == 'b' || s[c] == 'B')
			{
				sol = new Bishop(Point(j, i), s[c]);
			}
			else if (s[c] == 'q' || s[c] == 'Q')
			{
				sol = new Queen(Point(j, i), s[c]);
			}
			else if (s[c] == 'p' || s[c] == 'P')
			{
				sol = new Pawn(Point(j, i), s[c]);
			}
			else
			{
				sol = nullptr;
			}
			this->_board[i][j] = sol;
			c++;
		}
	}
}

/*
this method is the d'tor of the board object
input: non
output: non
*/
Board::~Board()
{
	//deleting all the dynamic memory
	char c;
	for (int i = 0; i < THE_MATRIX; i++)
	{
		for (int j = 0; j < THE_MATRIX; j++)
		{
			if (this->_board[i][j] != nullptr)
			{
				c = this->_board[i][j]->getTypeAndColor();
				/*if (this->_board[i][j]->getRun() != nullptr)
				{
					delete this->_board[i][j]->getRun(); when i try to do that there is an error
					delete this->_board[i][j]->getTower(); when i try to do that there is an error
				}*/
				if (c != 'B' && c != 'b' && c != 'R' && c != 'r' && c != HASHTAG)
					delete this->_board[i][j];
			}
		}
	}
}

/*
this method checks the move code
input: start point wanted point and the wich player's turn is it
output: int - the move code
*/
int Board::checkMove(Point loc, Point newLoc, const char turn)
{
	Soldier* s, * dest;
	s = this->_board[loc.getY()][loc.getX()];
	dest = this->_board[newLoc.getY()][newLoc.getX()];
	if ((s->getColor() == BLACK && turn == WHITE) || (s->getColor() == WHITE && turn == BLACK))//the selected paw is not the player's paw
	{
		return 2;
	}
	else if ((dest->getColor() == WHITE && turn == WHITE) || (dest->getColor() == BLACK && turn == BLACK))// if the dest has the same color paw
	{
		return 3;
	}
	if (s->move(newLoc, *this))//move of player is valid
	{
		this->moveSol(loc, newLoc);
		if (this->checkChes(turn))
		{
			this->moveSol(newLoc, loc);
			return 4;
		}
	}
	else//the move is not valid
	{
		return 6;
	}
	this->_board[newLoc.getY()][newLoc.getX()]->incNumOfMoves();
	//need to check chess
	if (turn == WHITE)
	{
		return this->checkChes(BLACK) ? 1 : 0;
	}
	return this->checkChes(WHITE) ? 1 : 0;
}

/*
this method converts the board to a string that the FE can read
input: an array of chars to put the string in
output: non
*/
void Board::boardToString(char * toRet)
{
	int c = 0;
	for (int i = THE_MATRIX - 1; i >= 0; i--)
	{
		for (int j = 0; j < THE_MATRIX; j++)
		{
			toRet[c] = this->_board[i][j]->getTypeAndColor();
			c++;
		}
	}
	toRet[64] = '0';
}

/*
this method checks if there is a chess on the asked player
input: the color of the asked player
output: bool - true if there is chess, false otherwise
*/
bool Board::checkChes(const char color)
{
	Point loc;
	Soldier* s;
	loc = this->getKingLoc(color);
	for (int i = 0; i < THE_MATRIX; i++)
	{
		for (int j = 0; j < THE_MATRIX; j++)
		{
			s = this->_board[i][j];
			if (((s->getColor() == BLACK && color == WHITE) || (s->getColor() == WHITE && color == BLACK)) && s->move(loc, *this))
			{
				return true;
			}
		}
	}
	return false;
}

/*
this method gets the king location
input: the color of the asked king
output: the Point of the king
*/
Point Board::getKingLoc(const char color)
{
	Soldier* s;
	for (int i = 0; i < THE_MATRIX; i++)
	{
		for (int j = 0; j < THE_MATRIX; j++)
		{
			s = this->_board[i][j];
			if ((s->getTypeAndColor() == 'K' && color == WHITE) || (s->getTypeAndColor() == 'k' && color == BLACK))
			{
				return this->_board[i][j]->getPoint();
			}
		}
	}
	return Point();
}

/*
this method is moooving the soldier in the board
input: the location of the soldier, the wanted location for the soldier
output: non
*/
void Board::moveSol(Point loc, Point newLoc)
{
	char c;
	c = this->_board[newLoc.getY()][newLoc.getX()]->getTypeAndColor();
	if (c != HASHTAG)
	{
		/*if (this->_board[newLoc.getY()][newLoc.getX()]->getRun() != nullptr)
		{
			delete this->_board[newLoc.getY()][newLoc.getX()]->getRun(); //when i try to do that there is an error
			delete this->_board[newLoc.getY()][newLoc.getX()]->getTower(); //when i try to do that there is an error
		}*/
		if (c != 'B' && c!= 'b' && c != 'R' && c != 'r')
			delete this->_board[newLoc.getY()][newLoc.getX()];
	}
	this->_board[newLoc.getY()][newLoc.getX()] = this->_board[loc.getY()][loc.getX()];
	this->_board[newLoc.getY()][newLoc.getX()]->getPoint() = newLoc;
	if (this->_board[newLoc.getY()][newLoc.getX()]->getRun() != nullptr)
	{
		this->_board[newLoc.getY()][newLoc.getX()]->getRun()->getPoint() = newLoc;
		this->_board[newLoc.getY()][newLoc.getX()]->getTower()->getPoint() = newLoc;
	}
	this->_board[loc.getY()][loc.getX()] = nullptr;
}

/*
this method gets the soldier in a point in the board
input: a location
output: the type and color of the soldier in the board
*/
char Board::getSolInLoc(Point* loc)
{
	char ret = this->_board[loc->getY()][loc->getX()]->getTypeAndColor();
	delete loc;
	return ret;
}

/*
this method prints the board (used it for myself not important to the game)
input: non
output: non
*/
void Board::printBoard()
{
	for (int i = THE_MATRIX - 1; i >= 0; i--)
	{
		std::cout << (char)(i + '0' + 1) << " ";
		for (int j = 0; j < THE_MATRIX; j++)
		{
			std::cout << this->_board[i][j]->getTypeAndColor() << " ";
		}
		std::cout << "\n";
	}
	std::cout << "  a b c d e f g h\n";
}

