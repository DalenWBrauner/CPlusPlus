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


int main()
{
	cout << "\n~~~~~\tTEST01()\t~~~~~\n";	Test01();
//	cout << "\n~~~~~\tTEST02()\t~~~~~\n";	Test02();
//	cout << "\n~~~~~\tTEST03()\t~~~~~\n";	Test03();
//	cout << "\n~~~~~\tTEST04()\t~~~~~\n";	Test04();
//	cout << "\n~~~~~\tTEST05()\t~~~~~\n";	Test05();
//	cout << "\n~~~~~\tTEST06()\t~~~~~\n";	Test06();
}
