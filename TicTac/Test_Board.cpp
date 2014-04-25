#include <iostream>
#include "Board.cpp"
using namespace std;

void Test01()
/* Outputs what appears to be an entire game of TicTacToe */
{
	ToeBoard t0;
	ToeBoard t1( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	ToeBoard t2( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	ToeBoard t3( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	ToeBoard t4( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	ToeBoard t5( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t6( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t7( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,1,0}} );
	ToeBoard t8( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,0,0}} );
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
/* Runs debug on an entire game of TicTacToe */
{
	ToeBoard t0(1);
	ToeBoard t1(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	ToeBoard t2(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	ToeBoard t3(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	ToeBoard t4(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	ToeBoard t5(1, {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t6(1, {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t7(1, {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,1,0}} );
	ToeBoard t8(1, {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,0,0}} );
	ToeBoard t9(1, {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,0}} );
}

void Test03()
/* Checks whose turn it is throughout the game */
{
	ToeBoard t0;
	ToeBoard t1( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,1},{1,1,1}} );
	ToeBoard t2( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{1,1,1}} );
	ToeBoard t3( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,1,0},{0,1,1}} );
	ToeBoard t4( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{1,0,0},{0,1,1}} );
	ToeBoard t5( {{0,1,1},{1,0,0},{1,0,1}}, {{1,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t6( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,1,1}} );
	ToeBoard t7( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,1,0}} );
	ToeBoard t8( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,0,0}} );
	ToeBoard t9( {{0,1,1},{1,0,0},{1,0,1}}, {{0,0,0},{0,0,0},{0,0,0}} );

	t0.english_Turn();
	t1.english_Turn();
	t2.english_Turn();
	t3.english_Turn();
	t4.english_Turn();
	t5.english_Turn();
	t6.english_Turn();
	t7.english_Turn();
	t8.english_Turn();
	t9.english_Turn();
}
void Test04()
/* Checks takeTurn() */
{
	ToeBoard ttt;			ttt.english_Turn();
	ttt.takeTurn(2,0,1);	ttt.english_Turn();
	ttt.takeTurn(2,1,0);	ttt.english_Turn();
	ttt.takeTurn(0,2,1);	ttt.english_Turn();
	ttt.takeTurn(1,1,0);	ttt.english_Turn();
	ttt.takeTurn(0,1,1);	ttt.english_Turn();
	ttt.takeTurn(0,0,0);	ttt.english_Turn();
	ttt.takeTurn(2,2,1);	ttt.english_Turn();
	ttt.takeTurn(1,2,0);	ttt.english_Turn();
	ttt.takeTurn(1,0,1);	ttt.english_Turn();
}

void Test05()
/* Checks gameOver() */
{
	ToeBoard ttt( {{0,1,1},{1,0,0},{1,0,1}}, {{0,1,0},{0,0,0},{0,0,0}} );
	cout << ttt;
	ttt.english_gameOver(); cout << "\n";

	ttt.takeTurn(1,0,1);
	cout << ttt;
	ttt.english_gameOver(); cout << "\n";

	ToeBoard tt0( {{1,1,1},{1,1,1},{1,1,1}}, {{0,1,1},{0,1,1},{0,1,1}} );
	cout << tt0;
	tt0.english_gameOver(); cout << "\n";

	ToeBoard tt1( {{1,1,1},{1,1,1},{1,1,1}}, {{0,1,1},{1,0,1},{0,1,1}} );
	cout << tt1;
	tt1.english_gameOver(); cout << "\n";

	ToeBoard tt2( {{1,1,1},{1,1,1},{1,1,1}}, {{0,1,1},{1,0,1},{1,1,0}} );
	cout << tt2;
	tt2.english_gameOver(); cout << "\n";

	ToeBoard tt3( {{0,1,1},{0,1,1},{0,1,1}}, {{0,1,1},{0,1,1},{0,1,1}} );
	cout << tt3;
	tt3.english_gameOver(); cout << "\n";

	ToeBoard tt4( {{0,1,1},{0,0,1},{0,0,1}}, {{0,0,0},{1,0,0},{1,0,0}} );
	cout << tt4;
	tt4.english_gameOver(); cout << "\n";

	ToeBoard tt5;
	cout << tt5;
	tt5.english_gameOver(); cout << "\n";

	ToeBoard tt6( {{0,1,1},{0,0,1},{0,0,1}}, {{1,1,1},{0,1,0},{1,0,0}} );
	cout << tt6;
	tt6.english_gameOver(); cout << "\n";

	ToeBoard tt7( {{1,1,0},{0,0,1},{1,0,0}}, {{0,0,0},{1,0,1},{1,1,0}} );
	cout << tt7;
	tt7.english_gameOver(); cout << "\n";

	tt7.takeTurn(0,2,1);
	cout << tt7;
	tt7.english_gameOver(); cout << "\n";

	tt7.takeTurn(2,1,0);
	cout << tt7;
	tt7.english_gameOver(); cout << "\n";
}

void Test06()
/* Checks creating boards from other boards */
{
	ToeBoard tttOriginal;
	tttOriginal.takeTurn(1,1,1);
	cout << tttOriginal;

	ToeBoard ttt2 = tttOriginal;
	ToeBoard ttt3 = tttOriginal;
	ttt2.takeTurn(0,0,0);
	ttt3.takeTurn(2,2,0);
	cout << ttt2;
	cout << ttt3;
}

int main()
{
	cout << "\n~~~~~\tTEST01()\t~~~~~\n";	Test01();
	cout << "\n~~~~~\tTEST02()\t~~~~~\n";	Test02();
	cout << "\n~~~~~\tTEST03()\t~~~~~\n";	Test03();
	cout << "\n~~~~~\tTEST04()\t~~~~~\n";	Test04();
	cout << "\n~~~~~\tTEST05()\t~~~~~\n";	Test05();
	cout << "\n~~~~~\tTEST06()\t~~~~~\n";	Test06();
}
