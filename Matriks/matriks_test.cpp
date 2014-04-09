#include <iostream>
#include "matriks.cpp"

using namespace std;

////////
// Matrix Tests
///
void test01()
{
	cout << "\n\tBEGIN:\ttest01()\t";
	cout << "\tTesting default matrix creation;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tTest does not terminate.\n\n";

	matriks<int> MX;
	cout << "matriks<int> MX;\n";

	cout << "\n\tEND:\ttest01()\n\n";
}

void test02()
{
	cout << "\n\tBEGIN:\ttest02()\t";
	cout << "\tTesting .size();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tTest does not terminate.\n\n";

	matriks<int> MX;
	cout << "matriks<int> MX;\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";
	
	cout << "\n\tEND:\ttest02()\n\n";
}

void test03()
{
	cout << "\n\tBEGIN:\ttest03()\t";
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
	
	cout << "\n\tEND:\ttest03()\n\n";
}

void test04()
{
	cout << "\n\tBEGIN:\ttest04()\t";
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
	
	cout << "\n\tEND:\ttest04()\n\n";
}

void test05()
{
	cout << "\n\tBEGIN:\ttest05()\t";
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
	
	cout << "\n\tEND:\ttest05()\n\n";
}

void test06()
{
	cout << "\n\tBEGIN:\ttest06()\t";
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
	
	cout << "\n\tEND:\ttest06()\n\n";
}

void test06point5()
{
	cout << "\n\tBEGIN:\ttest06.5()\t";
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

	cout << "\n\tEND:\ttest06.5()\n\n";
}


void test07()
{
	cout << "\n\tBEGIN:\ttest07()\t";
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
	
	cout << "\n\tEND:\ttest07()\n\n";
}

void test08()
{
	cout << "\n\tBEGIN:\ttest08()\t";
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
	
	cout << "\n\tEND:\ttest08()\n\n";
}

void test09()
{
	cout << "\n\tBEGIN:\ttest09()\t";
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
	
	cout << "\n\tEND:\ttest09()\n\n";
}

void test10()
{
	cout << "\n\tBEGIN:\ttest10()\t";
	cout << "\tTesting .transpose();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe supposed transpose is in fact transposed.\n\n";

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<vector<short>> Victor = {Abby, Bobby};
	matriks<short> Mario = Victor;
	matriks<short> Maria = Mario.transpose();
	
	cout << Mario << "\n";	
	cout << Maria << "\n";
	cout << "\n\tEND:\ttest10()\n\n";
}

////////
// Matrix Operation Tests
///
void test_op01()
{
	cout << "\n\tBEGIN:\ttest_op01()\t";
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
	
	cout << "\n\tEND:\ttest_op01()\n\n";
}

void test_op02()
{
	cout << "\n\tBEGIN:\ttest_op02()\t";
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
	
	cout << "\n\tEND:\ttest_op02()\n\n";
}

void test_op03()
{
	cout << "\n\tBEGIN:\ttest_op03()\t";
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

	cout << "\n\tEND:\ttest_op03()\n\n";
}

void test_op04()
{
	cout << "\n\tBEGIN:\ttest_op04()\t";
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

	cout << "\n\tEND:\ttest_op04()\n\n";
}

void test_op05()
{
	cout << "\n\tBEGIN:\ttest_op05()\t";
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

	cout << "\n\tEND:\ttest_op05()\n\n";
}

void test_op06()
{
	cout << "\n\tBEGIN:\ttest_op06()\t";
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

	cout << "\n\tEND:\ttest_op06()\n\n";
}

void test_op07()
{
	cout << "\n\tBEGIN:\ttest_op07()\t";
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
	
	cout << "\n\tEND:\ttest_op07()\n\n";
}

void test_op08()
{
	cout << "\n\tBEGIN:\ttest_op08()\t";
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
	
	cout << "\n\tEND:\ttest_op08()\n\n";
}

void test_op09()
{
	cout << "\n\tBEGIN:\ttest_op09()\t";
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
	
	cout << "\n\tEND:\ttest_op09()\n\n";
}

void test_op10()
{
	cout << "\n\tBEGIN:\ttest_op10()\t";
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
	
	cout << "\n\tEND:\ttest_op10()\n\n";
}

void test_op11()
{
	cout << "\n\tBEGIN:\ttest_op11()\t";
	cout << "\tTesting == operator for matrikies against non-matrikies;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tMatrikies are accurately compared.\n";
	cout << "\t*\t(Nine 1s are output in a 3x3 form seperated by commas.)\n\n";

	matriks<int> Mario = 7;
	if (Mario == 7) { cout << "1,"; }

	matriks<int> Maria;
	Maria.resize(1,1);
	Maria[0][0] = 7;
	if (Maria == 7) { cout << "1,"; }

	vector<short> Jasmine = {99,111,73};
	matriks<short> Jasper = Jasmine;
	if (Jasper == Jasmine) { cout << "1\n"; }

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

	cout << "\n\tEND:\ttest_op11()\n\n";
}

////////
// Matrix Row-Operation Tests
///
void test_row01()
{
	cout << "\n\tBEGIN:\ttest_row01()\t";
	cout << "\tTesting .rowop_swap();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tA matriks' rows are properly swapped after the method call.\n\n";

	matriks<int> Maria;
	Maria.resize(4,2);
	for (auto i=0; i<4 ; ++i)
	{
		Maria[0][i] = (i+1);
		Maria[1][i] = 3*(i+1);
	}
	cout << Maria << "\n";

//	cout << "Now we'll swap rows 2 and 4!\n";
//	Maria.rowop_swap(2,4);						Terminates, as it should
	cout << "Now we'll swap rows 1 and 3!\n";
	Maria.rowop_swap(1,3);
	cout << Maria << "\n";
	cout << "\n\tEND:\ttest_row01()\n\n";
}

void test_row02()
{
	cout << "\n\tBEGIN:\ttest_row02()\t";
	cout << "\tTesting .rowop_scale();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tA matriks' rows are properly scaled after the method call.\n\n";

	matriks<int> Maria;
	Maria.resize(4,2);
	for (auto i=0; i<4 ; ++i)
	{
		Maria[0][i] = (i+1);
		Maria[1][i] = 3*(i+1);
	}
	cout << Maria << "\n";

//	cout << "Now we'll scale row 4 by 1!\n";
//	Maria.rowop_scale(4,1);						Terminates, as it should
	cout << "Now we'll scale row 1 by 3!\n";
	Maria.rowop_scale(1,3);
	cout << Maria << "\n";

	cout << "Now we'll scale row 2 by 4!\n";
	Maria.rowop_scale(2,4);
	cout << Maria << "\n";
	cout << "\n\tEND:\ttest_row02()\n\n";
}

void test_row03()
{
	cout << "\n\tBEGIN:\ttest_row03()\t";
	cout << "\tTesting .rowop_add();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tA matriks' rows are properly added after the method call.\n\n";

	matriks<float> Maria;
	Maria.resize(6,2);
	for (auto i=0; i<6 ; ++i)
	{
		Maria[0][i] = (i+1);
		Maria[1][i] = 3*(i+1);
	}
	cout << Maria << "\n";

	cout << "Now we'll add row 2 to 4 with a scalar of 1!\n";
	Maria.rowop_add(2,4,1);
	cout << Maria << "\n";
	cout << "Now we'll add row 0 to 3 with a scalar of -4!\n";
	Maria.rowop_add(0,3,-4);
	cout << Maria << "\n";
	cout << "Now we'll add row 1 to 2 with a scalar of 0!\n";
	Maria.rowop_add(1,2,0);
	cout << Maria << "\n";
	cout << "Now we'll add row 5 to 0 with a scalar of -1/6!\n";
	Maria.rowop_add(5,0,-1/6.0);
	cout << Maria << "\n";

	cout << "\n\tEND:\ttest_row03()\n\n";
}

void test_row04()
{
	cout << "\n\tBEGIN:\ttest_row04()\t";
	cout << "\tTesting various rowops;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe matriks is properly row-reduced to reduced echelon form.\n\n";

	matriks<float> Maria;
	Maria.resize(3,6);
	vector<float> v0 = {0, 3, 3};
	vector<float> v1 = {3, -7, -9};
	vector<float> v2 = {-6, 8, 12};
	vector<float> v3 = {6, -5, -9};
	vector<float> v4 = {4, 8, 6};
	vector<float> v5 = {-5, 9, 15};
	Maria[0] = v0;
	Maria[1] = v1;
	Maria[2] = v2;
	Maria[3] = v3;
	Maria[4] = v4;
	Maria[5] = v5;
	cout << Maria << "\n";

	Maria.rowop_scale(2,1/3.0);
	Maria.rowop_swap(0,2);
	Maria.rowop_add(0,1,-3);
	Maria.rowop_scale(1,0.5);
	Maria.rowop_add(1,2,-3);
	Maria.rowop_add(1,0,3);
	Maria.rowop_add(2,1,-1);
	Maria.rowop_add(2,0,-5);
	cout << "Some MYSTERIOUS row operations later...";
	cout << Maria << "\n";

	cout << "\n\tEND:\ttest_row04()\n\n";
}

void test_row04point5()
{
	cout << "\n\tBEGIN:\ttest_row04.5()\t";
	cout << "\tTesting manual rowops;\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tHold up, I need to try something...\n\n";

	matriks<float> Mario;
	Mario.resize(3,6);
	vector<float> v0 = {0, 3, 3};
	vector<float> v1 = {3, -7, -9};
	vector<float> v2 = {-6, 8, 12};
	vector<float> v3 = {6, -5, -9};
	vector<float> v4 = {4, 8, 6};
	vector<float> v5 = {-5, 9, 15};
	Mario[0] = v0;
	Mario[1] = v1;
	Mario[2] = v2;
	Mario[3] = v3;
	Mario[4] = v4;
	Mario[5] = v5;
	cout << Mario << "\n";

//	cout << "swap 0 & 1...\n";
	Mario.rowop_swap(0,1);
//	cout << Mario << "\n";

//	cout << "scale 0 by 1/3...\n";
	Mario.rowop_scale(0,1/3.0);
//	cout << Mario << "\n";

//	cout << "add 0 to 1 by -Mario[0][1]...\n";
//	cout << "add 0 to 2 by -Mario[0][2]...\n";
	Mario.rowop_add(0,1, -Mario[0][1] );
	Mario.rowop_add(0,2, -Mario[0][2] );
//	cout << Mario << "\n";

//	cout << "scale 1 by 1/3...\n";
	Mario.rowop_scale(1,1/3.0);
//	cout << Mario << "\n";

//	cout << "add 1 to 0 by -Mario[1][0]...\n";
//	cout << "add 1 to 2 by -Mario[1][2]...\n";
	Mario.rowop_add(1,0, -Mario[1][0] );
	Mario.rowop_add(1,2, -Mario[1][2] );
//	cout << Mario << "\n";

//	cout << "scale 2 by 3/2...\n";
	Mario.rowop_scale(2,3/2.0);
//	cout << Mario << "\n";

//	cout << -Mario[4][0] << "\n";
//	cout << -Mario[4][1] << "\n";
//	cout << "add 2 to 0 by -Mario[4][0]...\n";
//	cout << "add 2 to 1 by -Mario[4][1]...\n";
	Mario.rowop_add(2,0,-Mario[4][0]);
	Mario.rowop_add(2,1,-Mario[4][1]);

	cout << Mario << "\n";
	cout << "Ugh. I know this looks ugly, but I swear it's correct.\n";
	cout << "In fact, it's no different from the result of test_row04, save some decimal issues.\n";

	cout << "\n\tEND:\ttest_row04.5()\n\n";
}

void test_row05()
{
	cout << "\n\tBEGIN:\ttest_row05()\t";
	cout << "\tTesting reducedEchelon();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe matriks is properly row-reduced to reduced echelon form.\n\n";

	matriks<float> Maria;
	Maria.resize(3,6);
	vector<float> v0 = {0, 3, 3};
	vector<float> v1 = {3, -7, -9};
	vector<float> v2 = {-6, 8, 12};
	vector<float> v3 = {6, -5, -9};
	vector<float> v4 = {4, 8, 6};
	vector<float> v5 = {-5, 9, 15};
	Maria[0] = v0;
	Maria[1] = v1;
	Maria[2] = v2;
	Maria[3] = v3;
	Maria[4] = v4;
	Maria[5] = v5;
	cout << "Maria";
	cout << Maria << "\n";

	matriks<float> Mary = Maria.reducedEchelon();
	cout << "Mary";
	cout << Mary << "\n";

	cout << "\n\tEND:\ttest_row05()\n\n";
}

void test_row05continued()
{
	cout << "\n\tBEGIN:\ttest_row05continued()\t";
	cout << "\tTesting reducedEchelon();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tThe matriks is properly row-reduced to reduced echelon form.\n\n";

	matriks<float> Test_Problem_A;
	Test_Problem_A.resize(3,4);
	vector<float> A0 = {1, 2, 3};
	vector<float> A1 = {2, 4, 6};
	vector<float> A2 = {4, 6, 9};
	vector<float> A3 = {8, 8, 12};
	Test_Problem_A[0] = A0;
	Test_Problem_A[1] = A1;
	Test_Problem_A[2] = A2;
	Test_Problem_A[3] = A3;
	cout << "Test_Problem_A";
	cout << Test_Problem_A << "\n";
	matriks<float> Program_Response_A = Test_Problem_A.reducedEchelon();
	cout << "Program_Response_A";
	cout << Program_Response_A << "\n";

	matriks<float> Test_Problem_B;
	Test_Problem_B.resize(3,4);
	vector<float> B0 = {1, 2, 4};
	vector<float> B1 = {2, 4, 5};
	vector<float> B2 = {4, 5, 4};
	vector<float> B3 = {5, 4, 2};
	Test_Problem_B[0] = B0;
	Test_Problem_B[1] = B1;
	Test_Problem_B[2] = B2;
	Test_Problem_B[3] = B3;
	cout << "Test_Problem_B";
	cout << Test_Problem_B << "\n";
	matriks<float> Program_Response_B = Test_Problem_B.reducedEchelon();
	cout << "Program_Response_B";
	cout << Program_Response_B << "\n";


	cout << "\n\tEND:\ttest_row05()\n\n";
}


////////
// Matrix Inversion Tests
///
void test_inv01()
{
	cout << "\n\tBEGIN:\ttest_inv01()\t";
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
	
	cout << "\n\tEND:\ttest_inv01()\n\n";
}

void test_inv02()
{
	cout << "\n\tBEGIN:\ttest_inv02()\t";
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

	cout << "\n\tEND:\ttest_inv02()\n\n";
}

void test_inv03()
{
	cout << "\n\tBEGIN:\ttest_inv03()\t";
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

	cout << "\n\tEND:\ttest_inv03()\n\n";
}

void test_inv04()
{
	cout << "\n\tBEGIN:\ttest_inv04()\t";
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

	cout << "\n\tEND:\ttest_inv04()\n\n";
}

void test_inv05()
{
	cout << "\n\tBEGIN:\ttest_inv05()\t";
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

	cout << "\n\tEND:\ttest_inv05()\n\n";
}

void test_inv06()
{
	cout << "\n\tBEGIN:\ttest_inv05()\t";
	cout << "\tTesting isInverseOf();\n";
	cout << "\tSuccess is defined as:\n";
	cout << "\t*\tAbility to test for inverses.\n";
	cout << "\t*\tThis is totally unfinished.\n\n";

	matriks<float> original;
	original.resize(3,3);
	original[0][0] = 0;
	original[0][1] = 1;
	original[0][2] = 4;
	original[1][0] = 1;
	original[1][1] = 0;
	original[1][2] = -3;
	original[2][0] = 2;
	original[2][1] = 3;
	original[2][2] = 8;

	matriks<float> inverse;
	inverse.resize(3,3);
	inverse[0][0] = -9.0/2.0;
	inverse[0][1] = -2.0;
	inverse[0][2] = 3.0/2.0;
	inverse[1][0] = 7;
	inverse[1][1] = 4;
	inverse[1][2] = -2;
	inverse[2][0] = -3.0/2.0;
	inverse[2][1] = -1.0;
	inverse[2][2] = 1.0/2.0;

	if (inverse.isInverseOf(original)) { cout << "YAY IT WORKED!\n"; }
	else	{ cout << "Awww...\n"; }
	cout << "\n\tEND:\ttest_inv06()\n\n";
}


int main()
{
	cout << "main()\n{";
/*	
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
	test10();
*/
	cout << "Matrix Tests\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Matrix Operation Tests\n";
/*
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
*/
	cout << "Matrix Operation Tests\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Matrix Row-Operation Tests\n";

	test_row01();
	test_row02();
	test_row03();
	test_row04();
	test_row04point5();		// Don't discriminate against the ugly!
	test_row05();
	test_row05continued();

	cout << "Matrix Row-Operation Tests\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Matrix Inversion Tests\n";
/*
	test_inv01();
	test_inv02();
//	test_inv03();	Terminates, as it should!
	test_inv04();
	test_inv05();
	test_inv06();
*/
	cout << "}\n";
}
