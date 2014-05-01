#include <iostream>
#include <vector>
#include "Board.cpp"
using namespace std;

void play(bool debug)
{
	ToeBoard ttt;
	while (ttt.gameOver() < 0)
	{
		cout << ttt;
		ttt.english_Turn();
		
		short response = 99;
		short a = -1, b = -1;
		while (a < 0 || b < 0)
		{
			cin >> response;
			while (response < 1 || response > 9)
			{
				cout << "What was that? ";
				response = cin.get();
			}
			switch(response) {
				case 1:		a=0; b=2; break;
				case 2:		a=1; b=2; break;
				case 3:		a=2; b=2; break;
				case 4:		a=0; b=1; break;
				case 5:		a=1; b=1; break;
				case 6:		a=2; b=1; break;
				case 7:		a=0; b=0; break;
				case 8:		a=1; b=0; break;
				case 9:		a=2; b=0; break;
			}
			if (ttt.isEmpty(a,b)) { ttt.takeTurn( a,b, ttt.whoseTurn()); }
			else
			{
				a = -1; b = -1;
				cout << "Sorry, that space isn't empty!\n";
			}
		}
	}
	ttt.english_gameOver();
	cout << ttt;
}

int main()
{
	bool j = 1;
	while (j)
	{
		play(0);
		cout << "Enter 1 to play again. ";
		cin >> j;
		cout << "\n";
	}
}
