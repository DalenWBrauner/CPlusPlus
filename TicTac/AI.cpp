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

	short tryTurn(ToeBoard ttt, short x, short y)
	// Returns the result of a suggested move
	// Returns 7 if the move is impossible
	{
		if (ttt.gameOver() != -1)	{return 7;}
		else if (!ttt.isEmpty(x,y)) {return 7;}
		else
		{
			ttt.takeTurn(x,y,ttt.whoseTurn());
			return ttt.gameOver();
		}
	}

	vector<short> anyWinningMoves(ToeBoard ttt, bool whoAmI)
	// Returns an {x,y} winning move if it exists, otherwise returns {-1,-1}
	{
		// Tries every move
		for (short a=0; a<3; ++a) {
			for (short b=0; b<3; ++b) {
				if ( tryTurn(ttt, a,b) == whoAmI ) {
					vector<short> VICTORY = {a, b};
					return(VICTORY);
				}
			}
		}
		// If we've tried everything and haven't returned a victory yet
		vector<short> FAILURE = {-1, -1};
		return(FAILURE);
	}
/*
	vector<vector<short>> goodIdeas(ToeBoard ttt, bool whoAmI)
	// Returns a list of "good" moves
	{
//		vector<vector<short>> defensive_moves;
		vector<vector<short>> remaining_moves;
		short result;

		// Tries every move
		for (auto a=0; a<3; ++a) {
			for (auto b=0; b<3; ++b) {
				result = tryTurn(ttt, a,b);

				// If the move means you win, IMMEDIATELY do so
				if (result == whoAmI)
				{
					vector<vector<short>> WINNING_MOVE = {{a,b}};
					return (WINNING_MOVE);
				}
				// If the move is at least POSSIBLE
				else if (result != 7)
				{ remaining_moves.push_back({a,b}); }
			}
		}
		return remaining_moves;

//		// If there aren't any winning moves, send off your defensive ones!
//		if (defensive_moves.size() != 0)
//		{ return defensive_moves; }
//		// And if there aren't any defensive moves, send off literally anything else!
//		else
//		{ return remaining_moves; }
	}
*/

	void takeTurn(ToeBoard &ttt)
	// Brute-force tries to pick the next empty place in-sequence
	{
		bool whoAmI = ttt.whoseTurn();
		if (ttt.gameOver() == -1)
		{
//			if (ttt.anyWinningMoves(ttt, != {3,3} )
			
			// Try the center and some corners first
			if (ttt.isEmpty(1,1))	{ ttt.takeTurn(1,1,whoAmI); }
			else if (ttt.isEmpty(0,0))	{ ttt.takeTurn(0,0,whoAmI); }
			else if (ttt.isEmpty(2,0))	{ ttt.takeTurn(2,0,whoAmI); }
			else if (ttt.isEmpty(0,2))	{ ttt.takeTurn(0,2,whoAmI); }

			// Then try the edges
			else if (ttt.isEmpty(0,1))	{ ttt.takeTurn(0,1,whoAmI); }
			else if (ttt.isEmpty(2,1))	{ ttt.takeTurn(2,1,whoAmI); }
			else if (ttt.isEmpty(1,0))	{ ttt.takeTurn(1,0,whoAmI); }
			else if (ttt.isEmpty(1,2))	{ ttt.takeTurn(1,2,whoAmI); }

			// Final corner
			else if (ttt.isEmpty(2,2))	{ ttt.takeTurn(2,2,whoAmI); }

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
