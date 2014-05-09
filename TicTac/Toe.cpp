#include <iostream>
#include <vector>
#include <string>
#include "AI.cpp"
#include "../TooNice.cpp"
using namespace std;

void human_turn(bool debug, ToeBoard &ttt)
/* This code asks a human what move they'd like to make,
and checks that their request is a valid move before making it." */
{
	// Sets the human up with some 'incorrect' values
	string response = "Wrong";
	short a = -1, b = -1;

	// While these values are 'incorrect'
	while (a < 0 || b < 0)
	{
		// Gets the human's response
		getline(cin, response);

		// If it was a valid response, assign it properly
		if		(response == "1") { a=0; b=2; }
		else if	(response == "2") { a=1; b=2; }
		else if	(response == "3") { a=2; b=2; }
		else if	(response == "4") { a=0; b=1; }
		else if	(response == "5") { a=1; b=1; }
		else if	(response == "6") { a=2; b=1; }
		else if	(response == "7") { a=0; b=0; }
		else if	(response == "8") { a=1; b=0; }
		else if	(response == "9") { a=2; b=0; }
		// If it wasn't, we'll have to ask again.
		else	{ response = "Still wrong"; }


		// So if it was wrong, ask again and skip the next bit.
		if (response == "Still wrong") {cout << "What was that? ";}

		// If the response was valid and the space is empty, take the turn!
		else if (ttt.isEmpty(a,b))	{ ttt.takeTurn(a,b); }

		// If the response was valid but the space isn't empty, ask again!
		else
		{
			a = -1; b = -1;
			cout << "Sorry, that space isn't empty!\n";
		}
	}
}

void AI_turn(bool debug, ToeBoard &ttt, AI &ToeBot)
{
	ToeBot.takeTurn(ttt);
}

void one_player(bool debug)
/* Human v.s. AI gameplay */
{
	ToeBoard ttt;
	AI ToeBot;
	bool itsTheHumansTurn = 1;
	// While the game has yet to finish
	while (ttt.gameOver() < 0)
	{
		// Display the board
		cout << ttt;
		ttt.english_Turn();

		// Grab whose turn it is
		itsTheHumansTurn = ttt.whoseTurn();

		// And let them play!
		if (itsTheHumansTurn)	{ human_turn(debug, ttt); }
		else					{ AI_turn(debug, ttt, ToeBot); }
	}

	// Game over!
	ttt.english_gameOver();
	cout << ttt;
}

void two_player(bool debug)
/* Human v.s. Human gameplay */
{
	ToeBoard ttt;
	// While the game has yet to finish
	while (ttt.gameOver() < 0)
	{
		// Display the board
		cout << ttt;
		ttt.english_Turn();

		// And let them play!
		human_turn(debug, ttt);
	}

	// Game over!
	ttt.english_gameOver();
	cout << ttt;
}

int main()
/* Asks the user if && how they'd like to play. */
{
	bool playing = 1;
	bool players;
	while (playing)
	{
		players = askBoolNicely("How many additional players are there? ");
		if (players)	{ two_player(0); }
		else			{ one_player(0); }
		playing = askBoolNicely("Enter 1 to play again, 0 to quit. ");
	}
}
