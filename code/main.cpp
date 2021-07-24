#include "mainFunctions.h"

#define THE_INIT_STRING "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"
using std::cout;
using std::endl;
using std::string;


int main()
{
	int moveCode = 0, i = 0;
	char turn = WHITE;
	Board b(THE_INIT_STRING);
	srand(time_t(NULL));
	Pipe p;
	bool isConnect = p.connect();
	string msgFromGraphics;
	char msgToGraphics[1024] = { 0 };
	string ans;
	Point p1, p2;
	//while not connected to graphics keep trying if the user wants to
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return 0;
		}
	}
	cout << "connected";
	b.boardToString(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);
	msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		for (i = 0; i < 1024; i++)
		{
			msgToGraphics[i] = 0;
		}
		std::cout << "the board: \n";
		b.printBoard();
		string2TwoPoint(p1, p2, msgFromGraphics);
		moveCode = b.checkMove(p1, p2, turn);
		msgToGraphics[0] = (char)(moveCode + '0');
		if (moveCode < 2 || moveCode == 8)
		{
			if (turn == WHITE)
			{
				turn = BLACK;
			}
			else
			{
				turn = WHITE;
			}
		}
		cout << "move code: " << moveCode<<"\n" << turn << "\n";
		std::cout << "the board: \n";
		b.printBoard();
		p.sendMessageToGraphics(msgToGraphics);
		msgFromGraphics = p.getMessageFromGraphics();
	} 
	p.close();
	return 0;
}