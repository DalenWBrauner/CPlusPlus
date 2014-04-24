#include <iostream>
#include "Board.cpp"
using namespace std;

void Test01()
{
	// Outputs what appears to be an entire game of TicTacToe
	ToeBoard t0;
	ToeBoard t1( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	ToeBoard t2( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	ToeBoard t3( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	ToeBoard t4( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	ToeBoard t5( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t6( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,0,1}} );
	ToeBoard t7( {{0,1,1},{1,0,0},{1,0,1}}, {{1,0,0},{0,0,0},{0,0,1}} );
	ToeBoard t8( {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,1}} );
	ToeBoard t9( {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,0}} );
	cout << "\nTurn 0:\n" << t0;
	cout << "\nTurn 1:\n" << t1;
	cout << "\nTurn 2:\n" << t2;
	cout << "\nTurn 3:\n" << t3;
	cout << "\nTurn 4:\n" << t4;
	cout << "\nTurn 5:\n" << t5;
	cout << "\nTurn 6:\n" << t6;
	cout << "\nTurn 7:\n" << t7;
	cout << "\nTurn 8:\n" << t8;
	cout << "\nTurn 9:\n" << t9;
}

void Test02()
{
	// Runs debug on an entire game of TicTacToe
	ToeBoard t0(1);
	ToeBoard t1(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	ToeBoard t2(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	ToeBoard t3(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	ToeBoard t4(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	ToeBoard t5(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t6(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,0,1}} );
	ToeBoard t7(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,0,0},{0,0,0},{0,0,1}} );
	ToeBoard t8(1, {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,1}} );
	ToeBoard t9(1, {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,0}} );
}

void Test03()
{
	// Checks whose turn it is throughout the game
	ToeBoard t0;
	ToeBoard t1( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	ToeBoard t2( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	ToeBoard t3( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	ToeBoard t4( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	ToeBoard t5( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t6( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,0,1}} );
	ToeBoard t7( {{0,1,1},{1,0,0},{1,0,1}}, {{1,0,0},{0,0,0},{0,0,1}} );
	ToeBoard t8( {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,1}} );
	ToeBoard t9( {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,0}} );

	cout << "On turn " << t0.whichTurn();
	if (t0.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t1.whichTurn();
	if (t1.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t2.whichTurn();
	if (t2.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t3.whichTurn();
	if (t3.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t4.whichTurn();
	if (t4.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t5.whichTurn();
	if (t5.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t6.whichTurn();
	if (t6.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t7.whichTurn();
	if (t7.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t8.whichTurn();
	if (t8.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }
	cout << "On turn " << t9.whichTurn();
	if (t9.whoseTurn())	{ cout << ", it's X's turn!\n"; }
	else				{ cout << ", it's O's turn!\n"; }

}

int main()
{
	cout << "~~~~~\tTEST01()\n";	Test01();
	cout << "~~~~~\tTEST02()\n";	Test02();
	cout << "~~~~~\tTEST03()\n";	Test03();
}
