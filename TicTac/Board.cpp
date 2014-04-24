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
				else				{s << tb.XOXO[x][y];}
				if (y != 2)	{s << "|";}
			}
			if (x != 2)	{ cout << "\n-+-+-\n"; }
		}
		s << "\n";
		return(s);
	}

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
