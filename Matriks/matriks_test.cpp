#include <iostream>
#include "matriks.cpp"

using namespace std;

////////
// Matrix Tests
///
void test01()
{
	cout << "\n\n\tBEGIN:\ttest01()\t";
	cout << "\tTesting default matrix creation;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tTest does not terminate.\n\n";

	matriks<int> MX;
	cout << "matriks<int> MX;\n";

	cout << "\n\tEND:\ttest01()\n";
}

void test02()
{
	cout << "\n\n\tBEGIN:\ttest02()\t";
	cout << "\tTesting .size();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tTest does not terminate.\n\n";

	matriks<int> MX;
	cout << "matriks<int> MX;\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";
	
	cout << "\n\tEND:\ttest02()\n";
}

void test03()
{
	cout << "\n\n\tBEGIN:\ttest03()\t";
	cout << "\tTesting .hasElements();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMX has no elements.\n";
	cout << "\t*\tMX1 has elements.\n\n";

	matriks<int> MX;
	cout << "matriks<int> MX;\n";
	if (MX.hasElements())
	{ cout << "MX has elements!\n"; }
	else
	{ cout << "MX has no elements!\n"; }
	matriks<int> MX1 = 1;
	cout << "matriks<int> MX1 = 1;\n";
	if (MX1.hasElements())
	{ cout << "MX1 has elements!\n"; }
	else
	{ cout << "MX1 has no elements!\n"; }
	
	cout << "\n\tEND:\ttest03()\n";
}

void test04()
{
	cout << "\n\n\tBEGIN:\ttest04()\t";
	cout << "\tTesting matriks creation with 1 element;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks is one element tall.\n";
	cout << "\t*\tMatriks is one element wide.\n\n";

	matriks<int> MX = 7;
	cout << "matriks<int> MX = 7;\n";

	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";

	if (MX.hasElements())
	{ cout << "MX has elements!\n"; }
	else
	{ cout << "MX has no elements!\n"; }
	
	cout << "\n\tEND:\ttest04()\n";
}

void test05()
{
	cout << "\n\n\tBEGIN:\ttest05()\t";
	cout << "\tTesting matriks creation with 1 vector;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks is four elements tall.\n";
	cout << "\t*\tMatriks is one element wide.\n\n";

	vector<int> v = {1, 2, 3, 4};
	cout << "vector<int> v = {1, 2, 3, 4};\n";
	matriks<int> MX = v;
	cout << "matriks<int> MX = v;\n";

	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";

	if (MX.hasElements())
	{ cout << "MX has elements!\n"; }
	else
	{ cout << "MX has no elements!\n"; }
	
	cout << "\n\tEND:\ttest05()\n";
}

void test06()
{
	cout << "\n\n\tBEGIN:\ttest06()\t";
	cout << "\tTesting 3x4 matriks creation with composed vectors;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks is three elements tall.\n";
	cout << "\t*\tMatriks is four elements wide.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<short> Crabby = {7,8,9};
	vector<short> Debby = {10,11,12};
	cout << "vector<short> Abby = {1,2,3};\n";
	cout << "vector<short> Bobby = {4,5,6};\n";
	cout << "vector<short> Crabby = {7,8,9};\n";
	cout << "vector<short> Debby = {10,11,12};\n";
	vector<vector<short>> Victor = {Abby, Bobby, Crabby, Debby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby, Crabby, Debby};\n";

	cout << "matriks<int> MX = Victor;\n";
	matriks<short> MX = Victor;

	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";

	if (MX.hasElements())
	{ cout << "MX has elements!\n"; }
	else
	{ cout << "MX has no elements!\n"; }
	
	cout << "\n\tEND:\ttest06()\n";
}

void test06point5()
{
	cout << "\n\n\tBEGIN:\ttest06.5()\t";
	cout << "\tTesting matriks creation with composed vectors of inequal sizes;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tProgram terminates.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5};
	vector<short> Crabby = {7,8,9};
	cout << "vector<short> Abby = {1,2,3};\n";
	cout << "vector<short> Bobby = {4,5};\n";
	cout << "vector<short> Crabby = {7,8,9};\n";
	vector<vector<short>> Victor = {Abby, Bobby, Crabby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby, Crabby};\n";
	matriks<short> MX = Victor;

	cout << "\n\tEND:\ttest06.5()\n";
}


void test07()
{
	cout << "\n\n\tBEGIN:\ttest07()\t";
	cout << "\tTesting cout << matriks;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks output resembles input.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	cout << "vector<short> Abby = {1,2,3};\n";
	cout << "vector<short> Bobby = {4,5,6};\n";
	vector<vector<short>> Victor = {Abby, Bobby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby};\n";

	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;\n";

	cout << MX << "\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";
	
	cout << "\n\tEND:\ttest07()\n";
}

void test08()
{
	cout << "\n\n\tBEGIN:\ttest08()\t";
	cout << "\tTesting .resize();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks changes to given sizes.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<vector<short>> Victor = {Abby, Bobby};
	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;\n";

	cout << MX << "\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";

	MX.resize(7,2);
	cout << "MX.resize(7,2);\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";
	cout << MX << "\n";

	MX.resize(2,2);
	cout << "MX.resize(2,2);\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";
	cout << MX << "\n";

	MX.resize(2,4);
	cout << "MX.resize(2,4);\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";
	cout << MX << "\n";
	
	cout << "\n\tEND:\ttest08()\n";
}

void test09()
{
	cout << "\n\n\tBEGIN:\ttest09()\t";
	cout << "\tTesting .row();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tRow output matches matriks output.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<vector<short>> Victor = {Abby, Bobby};
	matriks<short> MX = Victor;
	
	vector<short> row0 = MX.row(0);
	vector<short> row1 = MX.row(1);
	vector<short> row2 = MX.row(2);

	cout << MX << "\n";
	cout << "Row 0: [" << row0[0] << ", " << row0[1] << "]\n";
	cout << "Row 1: [" << row1[0] << ", " << row1[1] << "]\n";
	cout << "Row 2: [" << row2[0] << ", " << row2[1] << "]\n";
	
	cout << "\n\tEND:\ttest09()\n";
}

////////
// Matrix Operation Tests
///
void test_op01()
{
	cout << "\n\n\tBEGIN:\ttest_op01()\t";
	cout << "\tTesting addition of two 3x2 matrikies;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe matriks is sucessfully added to itself.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	cout << "vector<short> Abby = {1,2,3};\n";
	cout << "vector<short> Bobby = {4,5,6};\n";
	vector<vector<short>> Victor = {Abby, Bobby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby};\n";

	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;\n";

	cout << MX << "\n";

	matriks<short> MXX = MX + MX;
	cout << "MXX = MX + MX;\n";

	cout << MXX << "\n";
	cout << "MXX is " << MXX.size()[0] << " elements tall.\n";
	cout << "MXX is " << MXX.size()[1] << " elements wide.\n";
	
	cout << "\n\tEND:\ttest_op01()\n";
}

void test_op02()
{
	cout << "\n\n\tBEGIN:\ttest_op02()\t";
	cout << "\tTesting subtraction of identical matrikies;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks are accurately subtracted.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	cout << "vector<short> Abby = {1,2,3};\n";
	cout << "vector<short> Bobby = {4,5,6};\n";
	vector<vector<short>> Victor = {Abby, Bobby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby};\n";

	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;\n";

	cout << MX << "\n";

	matriks<short> MXX = MX - MX;
	cout << "MXX = MX - MX;\n";

	cout << MXX << "\n";
	cout << "MXX is " << MXX.size()[0] << " elements tall.\n";
	cout << "MXX is " << MXX.size()[1] << " elements wide.\n";
	
	cout << "\n\tEND:\ttest_op02()\n";
}

void test_op03()
{
	cout << "\n\n\tBEGIN:\ttest_op03()\t";
	cout << "\tTesting subtraction of different-sized matrikies;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tTest terminates.\n\n";

	vector<short> Crabby = {7,8,9};
	cout << "vector<short> Crabby = {7,8,9};\n";
	vector<vector<short>> Kinda_Crabby = {Crabby, Crabby};
	vector<vector<short>> Super_Crabby = {Crabby, Crabby, Crabby, Crabby};
	cout << "vector<vector<short>> Kinda_Crabby = {Crabby, Crabby};\n";
	cout << "vector<vector<short>> Super_Crabby = {Crabby, Crabby, Crabby, Crabby};\n";

	matriks<short> Kinda_MX = Kinda_Crabby;
	matriks<short> Super_MX = Super_Crabby;
	matriks<short> New = Super_MX - Kinda_MX;
	cout << New << "\n";

	cout << "\n\tEND:\ttest_op03()\n";
}

void test_op04()
{
	cout << "\n\n\tBEGIN:\ttest_op04()\t";
	cout << "\tTesting scalar multiplication;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks is accurately multiplied.\n\n";

	vector<int> Abby = {1,2,3};
	vector<int> Bobby = {4,5,6};
	vector<int> Crabby = {7,8,9};
	vector<vector<int>> Victor = {Abby, Bobby, Crabby};

	matriks<int> Mx0 = Victor;
	matriks<int> Mx1 = Victor;
	matriks<int> Mx2 = Victor;
	cout << "matriks<int> Mx0 = Victor;\n";
	cout << "matriks<int> Mx1 = Victor;\n";
	cout << "matriks<int> Mx2 = Victor;\n";

	Mx0 = Mx0 * 0;
	Mx1 = Mx1 * 1;
	Mx2 = Mx2 * 2;
	cout << "matriks<int> Mx0 = Mx0 * 0;\n";
	cout << "matriks<int> Mx1 = Mx1 * 1;\n";
	cout << "matriks<int> Mx2 = Mx2 * 2;\n";

	cout << Mx0 << "\n";
	cout << Mx1 << "\n";
	cout << Mx2 << "\n";

	cout << "\n\tEND:\ttest_op04()\n";
}

void test_op05()
{
	cout << "\n\n\tBEGIN:\ttest_op05()\t";
	cout << "\tTesting vektor multiplication;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks is acurately multiplied.\n\n";

	vector<int> Abby = {1,2,3};
	vector<int> Bobby = {4,5,6};
	vector<int> Crabby = {7,8,9};
	vector<vector<int>> Victor = {Abby, Bobby, Crabby};

	vektor<int> Abbk = Abby;
	vektor<int> Bobbk = Bobby;
	vektor<int> Crabbk = Crabby;
	cout << "vektor<int> Abbk = Abby;\n";
	cout << "vektor<int> Bobbk = Bobby;\n";
	cout << "vektor<int> Crabbk = Crabby;\n";

	matriks<int> Mx0 = Victor;
	matriks<int> Mx1 = Victor;
	matriks<int> Mx2 = Victor;
	cout << "matriks<int> Mx0 = Victor;\n";
	cout << "matriks<int> Mx1 = Victor;\n";
	cout << "matriks<int> Mx2 = Victor;\n";

	double Result0 = Mx0 * Abbk;
	double Result1 = Mx1 * Bobbk;
	double Result2 = Mx2 * Crabbk;
	cout << "matriks<int> Result0 = Mx0 * Abbk;\n";
	cout << "matriks<int> Result1 = Mx1 * Bobbk;\n";
	cout << "matriks<int> Result2 = Mx2 * Crabbk;\n";

	cout << "1*1 + 2*2 + 3*3 + 4*1 + 5*2 + 6*3 + 7*1 + 8*2 + 9*3 ==  96 =? " << Result0 << "\n";
	if(!(96  == Result0)) { cout << "RESULT0 IS WRONG\n"; }
	cout << "1*4 + 2*5 + 3*6 + 4*4 + 5*5 + 6*6 + 7*4 + 8*5 + 9*6 == 231 =? " << Result1 << "\n";
	if(!(231 == Result1)) { cout << "RESULT1 IS WRONG\n"; }
	cout << "1*7 + 2*8 + 3*9 + 4*7 + 5*8 + 6*9 + 7*7 + 8*8 + 9*9 == 366 =? " << Result2 << "\n";
	if(!(366 == Result2)) { cout << "RESULT2 IS WRONG\n"; }

	cout << "\n\tEND:\ttest_op05()\n";
}

void test_op06()
{
	cout << "\n\n\tBEGIN:\ttest_op06()\t";
	cout << "\tTesting vector multiplication;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks is accurately multiplied.\n\n";

	vector<int> Abby = {1,2,3};
	vector<int> Bobby = {4,5,6};
	vector<int> Crabby = {7,8,9};
	vector<vector<int>> Victor = {Abby, Bobby, Crabby};

	matriks<int> Mx0 = Victor;
	matriks<int> Mx1 = Victor;
	matriks<int> Mx2 = Victor;
	cout << "matriks<int> Mx0 = Victor;\n";
	cout << "matriks<int> Mx1 = Victor;\n";
	cout << "matriks<int> Mx2 = Victor;\n";

	double	Result0 = Mx0 * Abby;
	double	Result1 = Mx1 * Bobby;
	double	Result2 = Mx2 * Crabby;
	cout << "matriks<int> Result0 = Mx0 * Abby;\n";
	cout << "matriks<int> Result1 = Mx1 * Bobby;\n";
	cout << "matriks<int> Result2 = Mx2 * Crabby;\n";

	cout << Result0 << "\n";
	cout << Result1 << "\n";
	cout << Result2 << "\n";

	cout << "\n\tEND:\ttest_op06()\n";
}

void test_op07()
{
	cout << "\n\n\tBEGIN:\ttest_op07()\t";
	cout << "\tTesting matrix multiplication;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatriks are accurately multiplied.\n\n";

	vector<int> Abby = {2,1};
	vector<int> Bobby = {3,-5,};
	vector<int> Crabby = {4,1};
	vector<int> Debby = {3,-2};
	vector<int> Ebby = {6,3};
	vector<vector<int>> Victoria = {Abby, Bobby};
	vector<vector<int>> Victor = {Crabby, Debby, Ebby};
	
	matriks<int> Maria = Victoria;
	matriks<int> Mario = Victor;
	matriks<int> Mark = Maria*Mario;

	cout << Maria << "\n";
	cout << "*\n";
	cout << Mario << "\n";
	cout << "=\n";
	cout << Mark << "\n";
	
	cout << "\n\tEND:\ttest_op07()\n";
}

void test_op08()
{
	cout << "\n\n\tBEGIN:\ttest_op08()\t";
	cout << "\tTesting invalid matrix multiplications;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tTest terminates.\n\n";

	vector<int> Abby = {2,1};
	vector<int> Bobby = {3,-5,};
	vector<int> Crabby = {4,1};
	vector<int> Debby = {3,-2};
	vector<int> Ebby = {6,3};
	vector<vector<int>> Victoria = {Abby, Bobby};
	vector<vector<int>> Victor = {Crabby, Debby, Ebby};
	
	matriks<int> Maria = Victoria;
	matriks<int> Mario = Victor;

	matriks<int> MarkI = Mario*Maria;	// Sizes are wrong
	matriks<int> MarkII = Mario*Mario;	// Sizes are wrong
	
	cout << "\n\tEND:\ttest_op08()\n";
}

void test_op09()
{
	cout << "\n\n\tBEGIN:\ttest_op09()\t";
	cout << "\tTesting [] operator;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tAccurate values are fetched, input and output.\n\n";

	matriks<int> Mark;
	Mark.resize(3,3);
	cout << "matriks<int> Mark;\n";
	cout << "Mark.resize(3,3);\n";
	cout << Mark << "\n";

	Mark[1][2] = 3;
	cout << "Mark[1][2] = 3\n";
	Mark[1][0] = 7;
	cout << "Mark[1][0] = 7\n";
	cout << Mark << "\n";

	vector<int> Vic = Mark[1];
	cout << "vector<int> Vic = Mark[1];\n";
	cout << "( " << Vic[0] << " " << Vic[1] << " " << Vic[2] << " )\n";
	
	cout << "\n\tEND:\ttest_op09()\n";
}

void test_op10()
{
	cout << "\n\n\tBEGIN:\ttest_op10()\t";
	cout << "\tTesting == operator for matrikies of various sizes;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatrikies are accurately compared.\n\n";

	matriks<int> Abby;
	matriks<int> Bobby;
	matriks<int> Crabby;
	matriks<int> Debby;
	matriks<int> Ebby;
	Abby.becomeIdentity(3);
	Bobby.becomeIdentity(3);
	Crabby.becomeIdentity(3);
	Debby.becomeIdentity(3);
	Ebby.becomeIdentity(7);

	cout << Abby << ": Abby\n";
	cout << Bobby << ": Bobby\n";
	cout << Crabby << ": Crabby\n";
	cout << Debby << ": Debby\n";
	cout << Ebby << ": Ebby\n";
	cout << "Abby == Abby : " << (Abby == Abby) << "\n";
	cout << "Abby == Bobby : " << (Abby == Bobby) << "\n";
	cout << "Abby == Crabby : " << (Abby == Crabby) << "\n";
	cout << "Abby == Debby : " << (Abby == Debby) << "\n";
	cout << "Ebby == Abby: " << (Ebby == Abby) << "\n";
	cout << "Ebby == Bobby: " << (Ebby == Bobby) << "\n";
	cout << "Ebby == Crabby: " << (Ebby == Crabby) << "\n";
	cout << "Ebby == Debby: " << (Ebby == Debby) << "\n";

	Abby[0][0] = 7;
	Debby[0][0] = 7;
	Ebby.becomeIdentity(3);
	Ebby[2][0] = 3;
	cout << Abby << ": Abby\n";
	cout << Bobby << ": Bobby\n";
	cout << Crabby << ": Crabby\n";
	cout << Debby << ": Debby\n";
	cout << Ebby << ": Ebby\n";
	cout << "Abby == Abby : " << (Abby == Abby) << "\n";
	cout << "Abby == Bobby : " << (Abby == Bobby) << "\n";
	cout << "Abby == Crabby : " << (Abby == Crabby) << "\n";
	cout << "Abby == Debby : " << (Abby == Debby) << "\n";
	cout << "Ebby == Abby: " << (Ebby == Abby) << "\n";
	cout << "Ebby == Bobby: " << (Ebby == Bobby) << "\n";
	cout << "Ebby == Crabby: " << (Ebby == Crabby) << "\n";
	cout << "Ebby == Debby: " << (Ebby == Debby) << "\n";
	
	cout << "\n\tEND:\ttest_op10()\n";
}

void test_op11()
{
	cout << "\n\n\tBEGIN:\ttest_op11()\t";
	cout << "\tTesting == operator for matrikies against non-matrikies;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatrikies are accurately compared.\n\n";

	matriks<int> Maria = 7;

	cout << (Maria == 7) << "\n";
/*
	vector<short> Maddie = {1,2,3};
	matriks<short> Maggie = Maddie;
	cout << (Maddie == Maddie) << ",";
	cout << (Maggie == Maggie) << ",";
	cout << (Maggie == Maddie) << "\n";

	vector<vector<short>> Marple = {Maddie,Maddie};
	matriks<short> Maaarrrrrrple = Marple;
	cout << (Marple == Marple) << ",";
	cout << (Maaarrrrrrple == Maaarrrrrrple) << ",";
	cout << (Maaarrrrrrple == Marple) << "\n";
	*/
	cout << "\n\tEND:\ttest_op11()\n";
}

void test_inv01()
{
	cout << "\n\n\tBEGIN:\ttest_inv01()\t";
	cout << "\tTesting .isSquare();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tIdentifying empty matrikies as not square.\n";
	cout << "\t*\tIdentifying 4x4 matrikies as square.\n";
	cout << "\t*\tIdentifying 2x4 matrikies as not square.\n";
	cout << "\t*\tIdentifying 4x2 matrikies as not square.\n\n";

	matriks<int> Mario;
	cout << "Let's give it up for Mario: ";
	cout << Mario;
	if(Mario.isSquare()) { cout << ", who is square!\n"; }
	else { cout << ", who is NOT square!\n"; }

	Mario.resize(4,4);
	cout << "Let's give it up for Mario: ";
	cout << Mario;
	if(Mario.isSquare()) { cout << ", who is square!\n"; }
	else { cout << ", who is NOT square!\n"; }

	Mario.resize(2,4);
	cout << "Let's give it up for Mario:";
	cout << Mario;
	if(Mario.isSquare()) { cout << ", who is square!\n"; }
	else { cout << ", who is NOT square!\n"; }

	Mario.resize(4,2);
	cout << "Let's give it up for Mario:";
	cout << Mario;
	if(Mario.isSquare()) { cout << ", who is square!\n"; }
	else { cout << ", who is NOT square!\n"; }
	
	cout << "\n\tEND:\ttest_inv01()\n";
}

void test_inv02()
{
	cout << "\n\n\tBEGIN:\ttest_inv02()\t";
	cout << "\tTesting determinant();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe determinant is successfully calculated.\n\n";
	
	matriks<int> Maria;
	Maria.resize(2,2);
	Maria[0][0] = 1;
	Maria[1][1] = 1;
	Maria[1][0] = 2;
	Maria[0][1] = 3;
	cout << "\n(1*1) - (2*3) = ";
	cout << Maria.determinant();
	Maria[0][0] = 3;
	Maria[1][1] = 4;
	Maria[1][0] = 2;
	Maria[0][1] = 6;
	cout << "\n(3*4) - (2*6) = ";
	cout << Maria.determinant();

	cout << "\n\tEND:\ttest_inv02()\n";
}

void test_inv03()
{
	cout << "\n\n\tBEGIN:\ttest_inv03()\t";
	cout << "\tTesting determinant();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe program terminates.\n\n";

	matriks<int> Maria;
	cout << ";\n";
	cout << Maria.determinant();
	Maria.resize(1,1);
	cout << ";\n";
	cout << Maria.determinant();
	Maria.resize(1,2);
	cout << ";\n";
	cout << Maria.determinant();
	Maria.resize(3,2);
	cout << ";\n";
	cout << Maria.determinant();
	Maria.resize(3,4);
	cout << ";\n";
	cout << Maria.determinant();
	Maria.resize(5,1);
	cout << ";\n";
	cout << Maria.determinant();
	cout << ";\n";

	cout << "\n\tEND:\ttest_inv03()\n";
}

void test_inv04()
{
	cout << "\n\n\tBEGIN:\ttest_inv04()\t";
	cout << "\tTesting becomeIdentity();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tAbility to generate identities of various sizes.\n\n";

	matriks<int> Maria;
	Maria.becomeIdentity(2);
	cout << Maria << "\n";
	Maria.becomeIdentity(3);
	cout << Maria << "\n";
	Maria.becomeIdentity(4);
	cout << Maria << "\n";
	Maria.becomeIdentity(7);
	cout << Maria << "\n";
	Maria.becomeIdentity(1);
	cout << Maria << "\n";
	Maria.becomeIdentity(0);
	cout << Maria << "\n";

	cout << "\n\tEND:\ttest_inv04()\n";
}

void test_inv05()
{
	cout << "\n\n\tBEGIN:\ttest_inv05()\t";
	cout << "\tTesting isIdentity();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tAbility to test for identities of various sizes.\n\n";

	matriks<int> Maria;
	Maria.becomeIdentity(2);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(3);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(4);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(7);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(1);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(0);
	cout << Maria.isIdentity() << "\n\n";

	Maria.becomeIdentity(2);
	Maria.resize(1,2);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(6);
	Maria.resize(6,2);
	cout << Maria.isIdentity() << "\n";
	Maria.becomeIdentity(7);
	Maria.resize(3,7);
	cout << Maria.isIdentity() << "\n\n";

	Maria.resize(2,2);
	Maria[0][0] = 0;
	Maria[0][1] = 0;
	Maria[1][0] = 0;
	Maria[1][1] = 0;
	cout << Maria.isIdentity() << "\n";
	Maria[0][0] = 1;
	cout << Maria.isIdentity() << "\n";
	Maria[1][1] = 1;
	cout << Maria.isIdentity() << "\n\n";

	Maria.resize(3,3);
	Maria[2][2] = 0;
	cout << Maria.isIdentity() << "\n";
	Maria[0][2] = 0;
	Maria[1][2] = 0;
	Maria[2][0] = 0;
	Maria[2][1] = 0;
	cout << Maria.isIdentity() << "\n";
	Maria[2][2] = 1;
	cout << Maria.isIdentity() << "\n";
	Maria[2][1] = 7;
	cout << Maria.isIdentity() << "\n";

	cout << "\n\tEND:\ttest_inv05()\n";
}



int main()
{
	cout << "main()\n{";
	
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
//	test06point5();	Terminates, as it should!
	test07();
	test08();
	test09();

	test_op01();
	test_op02();
//	test_op03();	Terminates, as it should!
	test_op04();
	test_op05();
	test_op06();
	test_op07();
//	test_op08();	Terminates, as it should!
	test_op09();
	test_op10();
	test_op11();

	test_inv01();
	test_inv02();
//	test_inv03();	Terminates, as it should!
	test_inv04();
	test_inv05();

	cout << "}\n";
}
