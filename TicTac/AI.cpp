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
			ttt.takeTurn(x,y);
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
		cout << "HAH, NOW IT'S MY TURN!\n";
		if (ttt.gameOver() == -1)
		{
			bool whoAmI = ttt.whoseTurn();

			// First, check if you can win!
			vector<short> cantWin = {-1,-1};

			cout << "FIRST, I'M GOING TO SEE IF I CAN WIN!\n";
			vector<short> winningMove = anyWinningMoves(ttt, whoAmI);
			cout << "OHHHHH, INTERESTING....\n";

			if (winningMove != cantWin)
			{
				cout << "MWAHAHAA, I WIN!\n";
				ttt.takeTurn(winningMove[0],winningMove[1]);
				cout << "HAH! AND THAT MEANS:\nYOU!\nLOSE!\n";
			}

			// Then try the center and most corners
			else if (ttt.isEmpty(1,1))	{ ttt.takeTurn(1,1); }
			else if (ttt.isEmpty(0,0))	{ ttt.takeTurn(0,0); }
			else if (ttt.isEmpty(2,0))	{ ttt.takeTurn(2,0); }
			else if (ttt.isEmpty(0,2))	{ ttt.takeTurn(0,2); }

			// Then try the edges
			else if (ttt.isEmpty(0,1))	{ ttt.takeTurn(0,1); }
			else if (ttt.isEmpty(2,1))	{ ttt.takeTurn(2,1); }
			else if (ttt.isEmpty(1,0))	{ ttt.takeTurn(1,0); }
			else if (ttt.isEmpty(1,2))	{ ttt.takeTurn(1,2); }

			// Then try the final corner
			else if (ttt.isEmpty(2,2))	{ ttt.takeTurn(2,2); }

			// Uh
			else
			{ cout << "W-Wait, I can't go anywhere! I thought the game wasn't over?\n"; }
		}
		else
		{cout << "The game is already over, I can't make any moves!\n"; }
	}
};

// Creation method
AI::AI() {}
