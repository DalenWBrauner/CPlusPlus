#include <iostream>
#include "AI.cpp"
//#include "Board.cpp"
using namespace std;

void Test01()
// The AI attempts to make a single turn in various scenarios
{
	AI ToeBot;

	ToeBoard t0, t1, t2, t3;
	t1.takeTurn(0,0,t1.whoseTurn());
	t2.takeTurn(1,1,t2.whoseTurn());
	t3.takeTurn(0,2,t3.whoseTurn());
	ToeBoard t4 = t1, t5 = t2, t6 = t3;
	t4.takeTurn(1,1,t4.whoseTurn());
	t5.takeTurn(0,1,t5.whoseTurn());
	t5.takeTurn(2,0,t5.whoseTurn());
	t6.takeTurn(2,1,t6.whoseTurn());
	t6.takeTurn(1,2,t6.whoseTurn());
	t6.takeTurn(2,2,t6.whoseTurn());

	cout << "Before AI\n" << t0;
	ToeBot.takeTurn(t0);
	cout << "After AI\n" << t0 << "\n";

	cout << "Before AI\n" << t1;
	ToeBot.takeTurn(t1);
	cout << "After AI\n" << t1 << "\n";

	cout << "Before AI\n" << t2;
	ToeBot.takeTurn(t2);
	cout << "After AI\n" << t2 << "\n";

	cout << "Before AI\n" << t3;
	ToeBot.takeTurn(t3);
	cout << "After AI\n" << t3 << "\n";

	cout << "Before AI\n" << t4;
	ToeBot.takeTurn(t4);
	cout << "After AI\n" << t4 << "\n";

	cout << "Before AI\n" << t5;
	ToeBot.takeTurn(t5);
	cout << "After AI\n" << t5 << "\n";

	cout << "Before AI\n" << t6;
	ToeBot.takeTurn(t6);
	cout << "After AI\n" << t6 << "\n";

	ToeBoard t9;
	cout << "Before AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
	ToeBot.takeTurn(t9);
	cout << "After AI\n" << t9;
}

void Test02()
// We test if the AI is able to correctly forsee the immediate outcome of a move
{
	int Tests = 0, Successes = 0;

	AI ToeBot;
	ToeBoard t0;

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,0) == -1) {Successes += 1;}
	else { cout << "Failed Test02.001\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,1) == -1) {Successes += 1;}
	else { cout << "Failed Test02.002\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,2) == -1) {Successes += 1;}
	else { cout << "Failed Test02.003\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,0) == -1) {Successes += 1;}
	else { cout << "Failed Test02.004\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,1) == -1) {Successes += 1;}
	else { cout << "Failed Test02.005\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,2,1) == -1) {Successes += 1;}
	else { cout << "Failed Test02.006\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,2) == -1) {Successes += 1;}
	else { cout << "Failed Test02.007\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,2) == -1) {Successes += 1;}
	else { cout << "Failed Test02.008\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,2,2) == -1) {Successes += 1;}
	else { cout << "Failed Test02.009\n"; }

	t0.takeTurn(0,0,0);

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,0) == 7) {Successes += 1;}
	else { cout << "Failed Test02.010\n"; }

	t0.takeTurn(1,1,0);

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,0) == 7) {Successes += 1;}
	else { cout << "Failed Test02.011\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,1) == 7) {Successes += 1;}
	else { cout << "Failed Test02.012\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,2,2) == -1) {Successes += 1;}
	else { cout << "Failed Test02.013\n"; }

	t0.takeTurn(1,0,1);
	t0.takeTurn(0,1,1);
	t0.takeTurn(0,2,1);

	// First attempt at identifying a potential victory
	Tests += 1;
	if (ToeBot.tryTurn(t0,2,2) == 0) {Successes += 1;}
	else { cout << "Failed Test02.014\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,0) == 7) {Successes += 1;}
	else { cout << "Failed Test02.015\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,1) == 7) {Successes += 1;}
	else { cout << "Failed Test02.016\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,2) == 7) {Successes += 1;}
	else { cout << "Failed Test02.017\n"; }

	// Time to verify the game is over
	t0.takeTurn(2,2,0);

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,0) == 7) {Successes += 1;}
	else { cout << "Failed Test02.021\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,1) == 7) {Successes += 1;}
	else { cout << "Failed Test02.022\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,2) == 7) {Successes += 1;}
	else { cout << "Failed Test02.023\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,0) == 7) {Successes += 1;}
	else { cout << "Failed Test02.024\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,1) == 7) {Successes += 1;}
	else { cout << "Failed Test02.025\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,2,1) == 7) {Successes += 1;}
	else { cout << "Failed Test02.026\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,0,2) == 7) {Successes += 1;}
	else { cout << "Failed Test02.027\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,1,2) == 7) {Successes += 1;}
	else { cout << "Failed Test02.028\n"; }

	Tests += 1;
	if (ToeBot.tryTurn(t0,2,2) == 7) {Successes += 1;}
	else { cout << "Failed Test02.029\n"; }

	cout << "Tests:\t\t" << Tests << "\nSuccesses:\t" << Successes << "\n";
}

void Test03()
// We test that the AI can spot winning moves
{
	int Tests = 0, Successes = 0;

	AI ToeBot;
	ToeBoard t0;

	vector<short> NoWins = {-1,-1};
	vector<short> v00 = {0,0};

	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,0) == NoWins) {Successes += 1;}
	else { cout << "Failed Test03.000\n"; }
	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,1) == NoWins) {Successes += 1;}
	else { cout << "Failed Test03.001\n"; }

	t0.takeTurn(1,1,1);
	
	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,0) == NoWins) {Successes += 1;}
	else { cout << "Failed Test03.002\n"; }
	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,1) == NoWins) {Successes += 1;}
	else { cout << "Failed Test03.003\n"; }

	t0.takeTurn(2,2,1);
	
	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,0) == NoWins) {Successes += 1;}
	else { cout << "Failed Test03.004\n"; }

	// This LOOKS like a victory, but really, the code CHECKS whose turn it is.
	// X has gone twice and O has never gone!
	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,1) == NoWins) {Successes += 1;}
	else { cout << "Failed Test03.005\n"; }

	t0.takeTurn(1,2,0);
	t0.takeTurn(2,1,0);

	Tests += 1;
	if (ToeBot.anyWinningMoves(t0,1) == v00) {Successes += 1;}
	else { cout << "Failed Test03.006\n"; }

	cout << "Tests:\t\t" << Tests << "\nSuccesses:\t" << Successes << "\n";
}

int main()
{
	cout << "\n~~~~~\tTEST01()\t~~~~~\n";	Test01();
	cout << "\n~~~~~\tTEST02()\t~~~~~\n";	Test02();
	cout << "\n~~~~~\tTEST03()\t~~~~~\n";	Test03();
//	cout << "\n~~~~~\tTEST04()\t~~~~~\n";	Test04();
//	cout << "\n~~~~~\tTEST05()\t~~~~~\n";	Test05();
//	cout << "\n~~~~~\tTEST06()\t~~~~~\n";	Test06();
}
