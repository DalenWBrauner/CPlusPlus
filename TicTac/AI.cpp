#include <iostream>
#include <vector>
#include <string>
#include "Board.cpp"
using namespace std;

class AI
{
	public:
		AI();	// Creation method

	friend ostream& operator<<(ostream& s, AI ai)
	// Cout output
	{
		s << "Oh, uh, hey. I'm the tic-tac-toe AI. I, uh... don't have much to say here, um...\n";
		return(s);
	}

	void takeTurn(ToeBoard &ttt)
	// Brute-force tries to pick the next empty place in-sequence
	{
		if( ttt.gameOver() == -1)
		{
			// Try the center and some corners first
			if (ttt.isEmpty(1,1))		{ ttt.takeTurn(1,1,ttt.whoseTurn()); }
			else if (ttt.isEmpty(0,0))	{ ttt.takeTurn(0,0,ttt.whoseTurn()); }
			else if (ttt.isEmpty(2,0))	{ ttt.takeTurn(2,0,ttt.whoseTurn()); }
			else if (ttt.isEmpty(0,2))	{ ttt.takeTurn(0,2,ttt.whoseTurn()); }

			// Then try the edges
			else if (ttt.isEmpty(0,1))	{ ttt.takeTurn(0,1,ttt.whoseTurn()); }
			else if (ttt.isEmpty(2,1))	{ ttt.takeTurn(2,1,ttt.whoseTurn()); }
			else if (ttt.isEmpty(1,0))	{ ttt.takeTurn(1,0,ttt.whoseTurn()); }
			else if (ttt.isEmpty(1,2))	{ ttt.takeTurn(1,2,ttt.whoseTurn()); }

			// Final corner
			else if (ttt.isEmpty(2,2))	{ ttt.takeTurn(2,2,ttt.whoseTurn()); }

			// Uh
			else
			{ cout << "I-I'm not sure how this happened, but I don't know what to do!\n"; }
		}
		else
		{cout << "Wait, the game is already over; I can't make any moves!\n"; }
	}
};

// Creation method
AI::AI() {}
