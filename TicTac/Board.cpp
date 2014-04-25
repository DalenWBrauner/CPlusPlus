#include <iostream>
#include <vector>
#include "../Trickster.cpp"
using namespace std;
typedef vector<vector<bool>> boolGrid;

class ToeBoard
{
	private:
		bool debug;			// Whether or not we are debugging
		boolGrid XOXO;		// Contains which spaces are 'X'=1 or 'O'=0
		boolGrid EMPTY;		// Contains which spaces are empty
		short HOW_EMPTY;	// Contains how many spaces are empty

	public:
		// Creation method
		ToeBoard();											// Create empty board
		ToeBoard(bool dbg);									// Create empty board w/ debug setting
		ToeBoard(boolGrid xoxo, boolGrid empty);			// Create preset board
		ToeBoard(bool dbg, boolGrid xoxo, boolGrid empty);	// Create preset board w/ debug setting

	friend ostream& operator<<(ostream& s, ToeBoard tb)
	/* Allows output via '<<' */
	{
		for (auto x=0; x<3; x++) {
			for (auto y=0; y<3; y++) {
				if (tb.EMPTY[x][y])	{s << " ";}
				else
				{
					if (tb.XOXO[x][y])	{cout << "X";}
					else				{cout << "O";}
				}
				if (y != 2)	{s << "|";}
			}
			if (x != 2)	{ cout << "\n-+-+-\n"; }
		}
		s << "\n";
		return(s);
	}

	// Debug methods
	void checkYourself()
	/* Couts private variables */
	{
		// debug
		cout << "debug: " << debug << ";\n";
		// XOXO
		cout << "XOXO:\n";
		for (auto x=0; x<3; x++) {
			for (auto y=0; y<3; y++) {
				cout << XOXO[x][y];
				if (y != 2)	{cout << "|";}
			}
			if (x != 2)	{ cout << "\n-+-+-\n"; }
		}
		cout << "\n";
		// EMPTY
		cout << "EMPTY:\n";
		for (auto x=0; x<3; x++) {
			for (auto y=0; y<3; y++) {
				cout << EMPTY[x][y];
				if (y != 2)	{cout << "|";}
			}
			if (x != 2)	{ cout << "\n-+-+-\n"; }
		}
		cout << "\n";
		// HOW_EMPTY
		cout << "HOW_EMPTY: " << HOW_EMPTY << ";\n";
	}

	void english_Turn()
	{
		cout << "TURN " << whichTurn();
		if (whoseTurn()) {cout << "; X's MOVE.\n";}
		else			 {cout << "; O's MOVE.\n";}
	}

	void english_gameOver()
	{
		short n = gameOver();
		if		(n==-1){ cout << "GAME NOT YET OVER.\n";}
		else if	(n== 0){ cout << "GAME OVER; O WINS.\n";}
		else if (n== 1){ cout << "GAME OVER; X WINS.\n";}
		else if (n== 2){ cout << "GAME OVER; NO WINNER.\n";}
		else {cout << "Uh... Have a look for yourself: " << n << "\n";}
	}

	// Info methods
	short whichTurn()
	/* Returns how many turns have passed */
	{ return (9 - HOW_EMPTY); }
	
	bool whoseTurn()
	/* Returns 1 if X's turn, 0 if O's turn */
	{
		short Xs = 0;
		short Os = 0;
		for (auto x=0; x<3; x++) {
			for (auto y=0; y<3; y++) {
				if (!EMPTY[x][y])
				{
					if (XOXO[x][y])	{Xs++;}
					else			{Os++;}
				}
			}
		}
		// X always goes first
		if (Xs > Os)	{return(0);}
		else			{return(1);}
	}

	bool isEmpty(short x, short y)
	{ return(EMPTY[y][x]); }

	short gameOver()
	/* returns:
	-1 if the game is not over
	0 if Os won
	1 if Xs won
	2 if the game is a tie
	*/
	{
		// Checks 3 spaces; should all of them be empty, the game cannot have been won.
		// Check the center isn't empty
		if (!EMPTY[1][1])
		{
			// Check the redundant diagonal
			if (!EMPTY[0][0] && !EMPTY[2][2] &&
				(XOXO[0][0]==XOXO[1][1]) && (XOXO[2][2]==XOXO[1][1]))
				{ return(XOXO[1][1]);}
			// Check the other diagonal
			if (!EMPTY[0][2] && !EMPTY[2][0] &&
				(XOXO[0][2]==XOXO[1][1]) && (XOXO[2][0]==XOXO[1][1]))
				{ return(XOXO[1][1]);}
			// Check the center row
			if (!EMPTY[0][1] && !EMPTY[2][1] &&
				(XOXO[0][1]==XOXO[1][1]) && (XOXO[2][1]==XOXO[1][1]))
				{ return(XOXO[1][1]);}
			// Check the center column
			if (!EMPTY[1][0] && !EMPTY[1][2] &&
				(XOXO[1][0]==XOXO[1][1]) && (XOXO[1][2]==XOXO[1][1]))
				{ return(XOXO[1][1]);}
		}
		// Check the top-left corner isn't empty
		if (!EMPTY[0][0])
		{
			// Checking the top row
			if (!EMPTY[0][1] && !EMPTY[0][2] &&
				(XOXO[0][1]==XOXO[0][0]) && (XOXO[0][2]==XOXO[0][0]))
				{ return(XOXO[0][0]);}
			// Checking the left column
			if (!EMPTY[1][0] && !EMPTY[2][0] &&
				(XOXO[1][0]==XOXO[0][0]) && (XOXO[2][0]==XOXO[0][0]))
				{ return(XOXO[0][0]);}
		}
		// Check the bottom-right corner isn't empty
		if (!EMPTY[2][2])
		{
			// Checking the bottom row
			if (!EMPTY[2][1] && !EMPTY[2][0] &&
				(XOXO[2][1]==XOXO[2][2]) && (XOXO[2][0]==XOXO[2][2]))
				{ return(XOXO[2][2]);}
			// Checking the right column
			if (!EMPTY[1][2] && !EMPTY[0][2] &&
				(XOXO[1][2]==XOXO[2][2]) && (XOXO[0][2]==XOXO[2][2]))
				{ return(XOXO[2][2]);}
		}
		// If there is no victory, then check for a tie.
		if (HOW_EMPTY == 0) {return  2;}
		// No victory and no tie means the game is not over.
		else				{return -1;}
	}
	
	
	// Interactive methods
	void takeTurn(short x, short y, bool xoxo)
	{
		XOXO[y][x] = xoxo;
		EMPTY[y][x] = 0;
		HOW_EMPTY--;
	}
};

/* Create empty board */
ToeBoard::ToeBoard()
{
	debug		= 0;
	XOXO		= {{1,1,1}, {1,1,1}, {1,1,1}};
	EMPTY		= {{1,1,1}, {1,1,1}, {1,1,1}};
	HOW_EMPTY	= 9;
}


/* Create empty board w/ debug setting */
ToeBoard::ToeBoard(bool dbg)
{
	debug		= dbg;
	XOXO		= {{1,1,1}, {1,1,1}, {1,1,1}};
	EMPTY		= {{1,1,1}, {1,1,1}, {1,1,1}};
	HOW_EMPTY	= 9;
	if (dbg)
	{
		cout << "Creating Empty board w/ debug...\n";
		checkYourself();
	}
}

/* Create preset board */
ToeBoard::ToeBoard(boolGrid xoxo, boolGrid empty)
{
	debug		= 0;
	XOXO		= xoxo;
	EMPTY		= empty;
	HOW_EMPTY	= 0;
	for (auto x=0; x<3; x++) {
		for (auto y=0; y<3; y++) {
			if(EMPTY[x][y]) {HOW_EMPTY++;}
		}
	}
}


/* Create preset board w/ debug setting */
ToeBoard::ToeBoard(bool dbg, boolGrid xoxo, boolGrid empty)
{
	debug		= dbg;
	XOXO		= xoxo;
	EMPTY		= empty;
	HOW_EMPTY	= 0;
	for (auto x=0; x<3; x++) {
		for (auto y=0; y<3; y++) {
			if(EMPTY[x][y]) {HOW_EMPTY++;}
		}
	}
	if (dbg)
	{
		cout << "Creating board w/ debug...\n";
		checkYourself();
	}
}
