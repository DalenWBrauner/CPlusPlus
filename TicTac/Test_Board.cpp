#include <iostream>
#include "Board.cpp"
using namespace std;

void Test01()
{
	// Outputs an entire game of TicTacToe
	ToeBoard t0;
	cout << "\nTurn 0:\n" << t0;

	ToeBoard t1( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	cout << "\nTurn 1:\n" << t1;

	ToeBoard t2( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	cout << "\nTurn 2:\n" << t2;

	ToeBoard t3( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	cout << "\nTurn 3:\n" << t3;

	ToeBoard t4( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	cout << "\nTurn 4:\n" << t4;

	ToeBoard t5( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	cout << "\nTurn 5:\n" << t5;

	ToeBoard t6( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,0,1}} );
	cout << "\nTurn 6:\n" << t6;

	ToeBoard t7( {{0,1,1},{1,0,0},{1,0,1}}, {{1,0,0},{0,0,0},{0,0,1}} );
	cout << "\nTurn 7:\n" << t7;

	ToeBoard t8( {{0,1,1},{1,0,0},{1,0,1}}, {{1,0,0},{0,0,0},{0,0,0}} );
	cout << "\nTurn 8:\n" << t8;

	ToeBoard t9( {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,0}} );
	cout << "\nTurn 9:\n" << t9;

}

int main()
{
	cout << "TEST01()\n";	Test01();
}
