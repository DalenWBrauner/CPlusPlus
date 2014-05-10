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
	// Returns the first {x,y} winning move if it exists, otherwise returns {-1,-1}
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

	vector<short> anyDefensiveMoves(ToeBoard ttt, bool whoAmI)
	// Returns the first {x,y} defensive move if it exists, otherwise returns {-1,-1}
	// A 'defensive' move is one that immediately prevents an opponent from winning.
	{
//		cout << "Okay people, let's take this from the top...\n";
		// Make an arbitrary move.
		short arb, itrary;
		bool breakingOut = 0;
//		cout << "We're starting our for loop, and";
		for (short A=0; A<3; ++A)
		{
			for (short B=0; B<3; ++B)
			{
//				cout << ".";
				if (ttt.isEmpty(A,B))
				{
					arb = A; itrary = B;
					breakingOut = 1;
//					cout << "we're out.\n";
					break;
				}
			}
			if (breakingOut) {break;}
		}
//		cout << "Okay good, we made it out.\n";
		ToeBoard ttt_arbitrary = ttt;
//		cout << "ToeBoard ttt_arbitrary = ttt;\n";
		ttt_arbitrary.takeTurn(arb,itrary);
//		cout << "ttt_arbitrary.takeTurn(arb,itrary);\n";
		
		// Check if your opponent now has any winning moves.
		vector<short> nonExistant = {-1,-1};
//		cout << "vector<short> nonExistant = {-1,-1};\n";
		vector<short> theirWinningMoves = anyWinningMoves(ttt_arbitrary, !whoAmI);
//		cout << "vector<short> theirWinningMoves = anyWinningMoves(ttt_arbitrary, !whoAmI);\n";

		// If they do, block 'em!
		if (theirWinningMoves != nonExistant)
		{
//			cout << "Hey, theirWinningMoves != nonExistant\n";
			return(theirWinningMoves);
		}

		// If they don't have any winning moves,
		//it might be because our last move prevented it.
		// Pick a new move and check the old one.

		// Find a new move
		short dif, ferent;
		breakingOut = 0;
//		cout << "Okay, so there's no defensive moves the first time.\n";
//		cout << "So this is arb: " << arb << "\n";
//		cout << "And this is itrary: " << itrary << "\n";
//		cout << "And this is itrary+1: " << (itrary+1) << "\n";
		for (short A=0; A<3; ++A)
		{
			for (short B=0; B<3; ++B)
			{
//				cout << A << ", " << B << "\n";
				if (ttt.isEmpty(A,B) && !(A == arb && B == itrary))
				{
//					cout << "Found an empty one: " << A << ", " << B << "\n";
					dif = A; ferent = B;
//					cout << "Again: " << dif << ", " << ferent << "\n";
					breakingOut = 1;
					break;
				}
//				else
//				{ cout << "Not empty: " << A << ", " << B << "\n";}
			}
			if (breakingOut) {break;}
		}
//		cout << "We've found a second arbitrary move,\n";
//		cout << "So this is arb: " << arb << "\n";
//		cout << "And this is itrary: " << itrary << "\n";
//		cout << "And this is itrary+1: " << (itrary+1) << "\n";
		// Make that move
		cout << dif << ", " << ferent << "\n";
		ttt.takeTurn(dif,ferent);
//		cout << "We've made a second arbitrary move,\n";

		// Okay, so check: if they move and win, block them!
		if (tryTurn(ttt, arb,itrary) == !whoAmI)
		{
//			cout << "And it resulted in their victory!\n";
			vector<short> lucky_guess = {arb, itrary};
			return(lucky_guess);
		}
		else
		{
//			cout << "And it changed nothing!\n";
			vector<short> anything_goes = {-1,-1};
			return(anything_goes);
		}
	}

	void takeTurn(ToeBoard &ttt)
	// BEEP BOOP TRY TO TAKE BEST TURN
	{
		cout << "HAH, NOW IT'S MY TURN!\n";

		// If the game is already over,		
		if (ttt.gameOver() != -1)
		{ cout << "HAHAHA- aww, the game is already over...\n"; }

		// If there's only one move left, find it and play it.
		else if (ttt.whichTurn() == 8)
		{
			cout << "Good game!\n";
			for (short A=0; A<3; ++A) {
				for (short B=0; B<3; ++B) {
					if (ttt.isEmpty(A,B))
					{
						ttt.takeTurn(A,B);
						return;
					}
				}
			}
			cout << "What? Wait, I thought there was just one move left...?\n";
		}

		// So if there's more than one option, you've got some thinking to do.
		else if (ttt.gameOver() == -1 && ttt.whichTurn() != 8)
		{
			// Figure out who you are,
			bool whoAmI = ttt.whoseTurn();

			// Check if you can win,
			vector<short> cantWin = {-1,-1};

			cout << "FIRST, I'M GOING TO SEE IF I CAN WIN!\n";
			vector<short> winningMove = anyWinningMoves(ttt, whoAmI);
			cout << "OHHHHH, INTERESTING....\n";

			// And if you can, do it!
			if (winningMove != cantWin)
			{
				cout << "MWAHAHAA, I WIN!\n";
				ttt.takeTurn(winningMove[0],winningMove[1]);
				cout << "HAH! AND THAT MEANS:\nYOU!\nLOSE!\n";
				return;
			}

			// No luck?
			cout << "HRM...\n";
			vector<short> defensiveMove = anyDefensiveMoves(ttt, whoAmI);
			cout << "HRRMMMMMM...\n";

			// Then check if you can block your opponent from winning!
			if (defensiveMove != cantWin)
			{
				cout << "WELL, IF I CAN'T WIN, I WON'T LET YOU, EITHER!\n";
				ttt.takeTurn(defensiveMove[0],defensiveMove[1]);
				cout << "AND YOU THOUGHT YOU COULD FOOL ME!\n";
				return;
			}
			
			// Nothing to block?
			cout << "HA! TAKE THAT!\n";

			// Then try the center and most corners
			if (ttt.isEmpty(1,1))	{ ttt.takeTurn(1,1); }
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
			{ cout << "W-Wait, I can't go anywhere! I thought the game wasn't over!\n"; }
		}
		else
		{ cout << "Hrm, I'm not sure how this happened.\n"; }
	}
};

// Creation method
AI::AI() {}
