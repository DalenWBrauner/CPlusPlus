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
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tTest does not terminate.\n";
	cout << endl;

	matriks<int> MX;
	cout << "matriks<int> MX;\n";

	cout << endl;
	cout << "\tEND:\ttest01()\n";
}

void test02()
{
	cout << "\n\tBEGIN:\ttest02()\t";
	cout << "\tTesting .size();\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tTest does not terminate.\n";
	cout << endl;

	matriks<int> MX;
	cout << "matriks<int> MX;\n";
	cout << "MX is " << MX.size()[0] << " elements tall.\n";
	cout << "MX is " << MX.size()[1] << " elements wide.\n";

	cout << endl;
	cout << endl;
	cout << "\tEND:\ttest02()\n";
}

void test03()
{
	cout << "\n\tBEGIN:\ttest03()\t";
	cout << "\tTesting .hasElements();\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMX has no elements.\n";
	cout << "\t*\tMX1 has elements.\n";
	cout << endl;

	matriks<int> MX;
	cout << "matriks<int> MX;" << endl;
	if (MX.hasElements())
	{ cout << "MX has elements!" << endl; }
	else
	{ cout << "MX has no elements!" << endl; }
	matriks<int> MX1 = 1;
	cout << "matriks<int> MX1 = 1;" << endl;
	if (MX1.hasElements())
	{ cout << "MX1 has elements!" << endl; }
	else
	{ cout << "MX1 has no elements!" << endl; }

	cout << endl;
	cout << "\tEND:\ttest03()\n";
}

void test04()
{
	cout << "\n\tBEGIN:\ttest04()\t";
	cout << "\tTesting matriks creation with 1 element;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks is one element tall.\n";
	cout << "\t*\tMatriks is one element wide.\n";
	cout << endl;

	matriks<int> MX = 7;
	cout << "matriks<int> MX = 7;" << endl;

	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;

	if (MX.hasElements())
	{ cout << "MX has elements!" << endl; }
	else
	{ cout << "MX has no elements!" << endl; }

	cout << endl;
	cout << "\tEND:\ttest04()\n";
}

void test05()
{
	cout << "\n\tBEGIN:\ttest05()\t";
	cout << "\tTesting matriks creation with 1 vector;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks is four elements tall.\n";
	cout << "\t*\tMatriks is one element wide.\n";
	cout << endl;

	vector<int> v = {1, 2, 3, 4};
	cout << "vector<int> v = {1, 2, 3, 4};" << endl;
	matriks<int> MX = v;
	cout << "matriks<int> MX = v;" << endl;

	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;

	if (MX.hasElements())
	{ cout << "MX has elements!" << endl; }
	else
	{ cout << "MX has no elements!" << endl; }

	cout << endl;
	cout << "\tEND:\ttest05()\n";
}

void test06()
{
	cout << "\n\tBEGIN:\ttest06()\t";
	cout << "\tTesting 3x4 matriks creation with composed vectors;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks is three elements tall.\n";
	cout << "\t*\tMatriks is four elements wide.\n";
	cout << endl;

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<short> Crabby = {7,8,9};
	vector<short> Debby = {10,11,12};
	cout << "vector<short> Abby = {1,2,3};" << endl;
	cout << "vector<short> Bobby = {4,5,6};" << endl;
	cout << "vector<short> Crabby = {7,8,9};" << endl;
	cout << "vector<short> Debby = {10,11,12};" << endl;
	vector<vector<short>> Victor = {Abby, Bobby, Crabby, Debby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby, Crabby, Debby};" << endl;

	matriks<short> MX = Victor;
	cout << "matriks<int> MX = Victor;" << endl;

	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;

	if (MX.hasElements())
	{ cout << "MX has elements!" << endl; }
	else
	{ cout << "MX has no elements!" << endl; }

	cout << endl;
	cout << "\tEND:\ttest06()\n";
}

void test07()
{
	cout << "\n\tBEGIN:\ttest07()\t";
	cout << "\tTesting cout << matriks;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks output resembles input.\n";
	cout << endl;

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	cout << "vector<short> Abby = {1,2,3};" << endl;
	cout << "vector<short> Bobby = {4,5,6};" << endl;
	vector<vector<short>> Victor = {Abby, Bobby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby};" << endl;

	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;" << endl;

	cout << MX << endl;
	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;
	
	cout << endl;
	cout << "\tEND:\ttest07()\n";
}

void test08()
{
	cout << "\n\tBEGIN:\ttest08()\t";
	cout << "\tTesting .resize();\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks changes to given sizes.\n";
	cout << endl;

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<vector<short>> Victor = {Abby, Bobby};
	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;" << endl;

	cout << MX << endl;
	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;

	MX.resize(7,2);
	cout << "MX.resize(7,2);" << endl;
	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;
	cout << MX << endl;

	MX.resize(2,2);
	cout << "MX.resize(2,2);" << endl;
	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;
	cout << MX << endl;

	MX.resize(2,4);
	cout << "MX.resize(2,4);" << endl;
	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;
	cout << MX << endl;

	cout << endl;
	cout << "\tEND:\ttest08()\n";
}

void test09()
{
	cout << "\n\tBEGIN:\ttest09()\t";
	cout << "\tTesting .row();\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tRow output matches matriks output.\n";
	cout << endl;

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	vector<vector<short>> Victor = {Abby, Bobby};
	matriks<short> MX = Victor;
	
	vector<short> row0 = MX.row(0);
	vector<short> row1 = MX.row(1);
	vector<short> row2 = MX.row(2);

	cout << MX << endl;
	cout << "Row 0: [" << row0[0] << ", " << row0[1] << "]" << endl;
	cout << "Row 1: [" << row1[0] << ", " << row1[1] << "]" << endl;
	cout << "Row 2: [" << row2[0] << ", " << row2[1] << "]" << endl;

	cout << endl;
	cout << "\tEND:\ttest09()\n";
}

////////
// Matrix Operation Tests
///
void test_op01()
{
	cout << "\n\tBEGIN:\ttest_op01()\t";
	cout << "\tTesting addition of two 3x2 matrikies;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tThe matriks is sucessfully added to itself.\n";
	cout << endl;

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	cout << "vector<short> Abby = {1,2,3};" << endl;
	cout << "vector<short> Bobby = {4,5,6};" << endl;
	vector<vector<short>> Victor = {Abby, Bobby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby};" << endl;

	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;" << endl;

	cout << MX << endl;

	matriks<short> MXX = MX + MX;
	cout << "MXX = MX + MX;" << endl;

	cout << MXX << endl;
	cout << "MXX is " << MXX.size()[0] << " elements tall." << endl;
	cout << "MXX is " << MXX.size()[1] << " elements wide." << endl;
	cout << endl;
	cout << "\tEND:\ttest_op01()\n";
}

void test_op02()
{
	cout << "\n\tBEGIN:\ttest_op02()\t";
	cout << "\tTesting subtraction of identical matrikies;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks are accurately subtracted.\n";
	cout << endl;

	vector<short> Abby = {1,2,3};
	vector<short> Bobby = {4,5,6};
	cout << "vector<short> Abby = {1,2,3};" << endl;
	cout << "vector<short> Bobby = {4,5,6};" << endl;
	vector<vector<short>> Victor = {Abby, Bobby};
	cout << "vector<vector<short>> Victor = {Abby, Bobby};" << endl;

	matriks<short> MX = Victor;
	cout << "matriks<short> MX = Victor;" << endl;

	cout << MX << endl;

	matriks<short> MXX = MX - MX;
	cout << "MXX = MX - MX;" << endl;

	cout << MXX << endl;
	cout << "MXX is " << MXX.size()[0] << " elements tall." << endl;
	cout << "MXX is " << MXX.size()[1] << " elements wide." << endl;
	cout << endl;
	cout << "\tEND:\ttest_op02()\n";
}

void test_op03()
{
	cout << "\n\tBEGIN:\ttest_op03()\t";
	cout << "\tTesting subtraction of different-sized matrikies;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tTest terminates.\n";
	cout << endl;

	vector<short> Crabby = {7,8,9};
	cout << "vector<short> Crabby = {7,8,9};" << endl;
	vector<vector<short>> Kinda_Crabby = {Crabby, Crabby};
	vector<vector<short>> Super_Crabby = {Crabby, Crabby, Crabby, Crabby};
	cout << "vector<vector<short>> Kinda_Crabby = {Crabby, Crabby};" << endl;
	cout << "vector<vector<short>> Super_Crabby = {Crabby, Crabby, Crabby, Crabby};" << endl;

	matriks<short> Kinda_MX = Kinda_Crabby;
	matriks<short> Super_MX = Super_Crabby;
	matriks<short> New = Super_MX - Kinda_MX;

	cout << New << endl;

	cout << endl;
	cout << "\tEND:\ttest_op03()\n";
}

void test_op04()
{
	cout << "\n\tBEGIN:\ttest_op04()\t";
	cout << "\tTesting scalar multiplication;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks is accurately multiplied.\n";
	cout << endl;

	vector<int> Abby = {1,2,3};
	vector<int> Bobby = {4,5,6};
	vector<int> Crabby = {7,8,9};
	vector<vector<int>> Victor = {Abby, Bobby, Crabby};

	matriks<int> Mx0 = Victor;
	matriks<int> Mx1 = Victor;
	matriks<int> Mx2 = Victor;
	cout << "matriks<int> Mx0 = Victor;" << endl;
	cout << "matriks<int> Mx1 = Victor;" << endl;
	cout << "matriks<int> Mx2 = Victor;" << endl;

	Mx0 = Mx0 * 0;
	Mx1 = Mx1 * 1;
	Mx2 = Mx2 * 2;
	cout << "matriks<int> Mx0 = Mx0 * 0;" << endl;
	cout << "matriks<int> Mx1 = Mx1 * 1;" << endl;
	cout << "matriks<int> Mx2 = Mx2 * 2;" << endl;

	cout << Mx0 << endl;
	cout << Mx1 << endl;
	cout << Mx2 << endl;

	cout << endl;
	cout << "\tEND:\ttest_op04()\n";
}

void test_op05()
{
	cout << "\n\tBEGIN:\ttest_op05()\t";
	cout << "\tTesting vektor multiplication;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks is acurately multiplied.\n";
	cout << endl;

	vector<int> Abby = {1,2,3};
	vector<int> Bobby = {4,5,6};
	vector<int> Crabby = {7,8,9};
	vector<vector<int>> Victor = {Abby, Bobby, Crabby};

	vektor<int> Abbk = Abby;
	vektor<int> Bobbk = Bobby;
	vektor<int> Crabbk = Crabby;
	cout << "vektor<int> Abbk = Abby;" << endl;
	cout << "vektor<int> Bobbk = Bobby;" << endl;
	cout << "vektor<int> Crabbk = Crabby;" << endl;

	matriks<int> Mx0 = Victor;
	matriks<int> Mx1 = Victor;
	matriks<int> Mx2 = Victor;
	cout << "matriks<int> Mx0 = Victor;" << endl;
	cout << "matriks<int> Mx1 = Victor;" << endl;
	cout << "matriks<int> Mx2 = Victor;" << endl;

	double Result0 = Mx0 * Abbk;
	double Result1 = Mx1 * Bobbk;
	double Result2 = Mx2 * Crabbk;
	cout << "matriks<int> Result0 = Mx0 * Abbk;" << endl;
	cout << "matriks<int> Result1 = Mx1 * Bobbk;" << endl;
	cout << "matriks<int> Result2 = Mx2 * Crabbk;" << endl;

	cout << "1*1 + 2*2 + 3*3 + 4*1 + 5*2 + 6*3 + 7*1 + 8*2 + 9*3 ==  96 =? " << Result0 << endl;
	if(!(96  == Result0)) { cout << "RESULT0 IS WRONG" << endl; }
	cout << "1*4 + 2*5 + 3*6 + 4*4 + 5*5 + 6*6 + 7*4 + 8*5 + 9*6 == 231 =? " << Result1 << endl;
	if(!(231 == Result1)) { cout << "RESULT1 IS WRONG" << endl; }
	cout << "1*7 + 2*8 + 3*9 + 4*7 + 5*8 + 6*9 + 7*7 + 8*8 + 9*9 == 366 =? " << Result2 << endl;
	if(!(366 == Result2)) { cout << "RESULT2 IS WRONG" << endl; }

	cout << endl;
	cout << "\tEND:\ttest_op05()\n";
}

void test_op06()
{
	cout << "\n\tBEGIN:\ttest_op06()\t";
	cout << "\tTesting vector multiplication;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks is accurately multiplied.\n";
	cout << endl;

	vector<int> Abby = {1,2,3};
	vector<int> Bobby = {4,5,6};
	vector<int> Crabby = {7,8,9};
	vector<vector<int>> Victor = {Abby, Bobby, Crabby};

	matriks<int> Mx0 = Victor;
	matriks<int> Mx1 = Victor;
	matriks<int> Mx2 = Victor;
	cout << "matriks<int> Mx0 = Victor;" << endl;
	cout << "matriks<int> Mx1 = Victor;" << endl;
	cout << "matriks<int> Mx2 = Victor;" << endl;

	double	Result0 = Mx0 * Abby;
	double	Result1 = Mx1 * Bobby;
	double	Result2 = Mx2 * Crabby;
	cout << "matriks<int> Result0 = Mx0 * Abby;" << endl;
	cout << "matriks<int> Result1 = Mx1 * Bobby;" << endl;
	cout << "matriks<int> Result2 = Mx2 * Crabby;" << endl;

	cout << Result0 << endl;
	cout << Result1 << endl;
	cout << Result2 << endl;

	cout << endl;
	cout << "\tEND:\ttest_op06()\n";
}

void test_op07()
{
	cout << "\n\tBEGIN:\ttest_op07()\t";
	cout << "\tTesting matrix multiplication;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tMatriks are accurately multiplied.\n";
	cout << endl;

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

	cout << Maria << endl;
	cout << "*\n";
	cout << Mario << endl;
	cout << "=\n";
	cout << Mark << endl;
	
	cout << endl;
	cout << "\tEND:\ttest_op07()\n";
}

void test_op08()
{
	cout << "\n\tBEGIN:\ttest_op08()\t";
	cout << "\tTesting invalid matrix multiplications;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tTest terminates.\n";
	cout << endl;

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
	
	cout << endl;
	cout << "\tEND:\ttest_op08()\n";
}

void test_op09()
{
	cout << "\n\tBEGIN:\ttest_op09()\t";
	cout << "\tTesting [] operator;\n";
	cout << "\tSUCCESS DEFINED AS:\n";
	cout << "\t*\tAccurate values are fetched, input and output.\n";
	cout << endl;

	matriks<int> Mark;
	Mark.resize(3,3);
	cout << "matriks<int> Mark;" << endl;
	cout << "Mark.resize(3,3);" << endl;
	cout << Mark << endl;

	Mark[1][2] = 3;
	cout << "Mark[1][2] = 3" << endl;
	Mark[1][0] = 7;
	cout << "Mark[1][0] = 7" << endl;
	cout << Mark << endl;

	vector<int> Vic = Mark[1];
	cout << "vector<int> Vic = Mark[1];" << endl;
	cout << "( " << Vic[0] << " " << Vic[1] << " " << Vic[2] << " )" << endl;

	cout << endl;
	cout << "\tEND:\ttest_op09()\n";
}

int main()
{
	cout << "main()\n{";
	
	cout << "\n" << endl;	test01();
	cout << "\n" << endl;	test02();
	cout << "\n" << endl;	test03();
	cout << "\n" << endl;	test04();
	cout << "\n" << endl;	test05();
	cout << "\n" << endl;	test06();
	cout << "\n" << endl;	test07();
	cout << "\n" << endl;	test08();
	cout << "\n" << endl;	test09();

	cout << "\n" << endl;	test_op01();
	cout << "\n" << endl;	test_op02();
//	cout << "\n" << endl;	test_op03();	Aborts, as it should!
	cout << "\n" << endl;	test_op04();
	cout << "\n" << endl;	test_op05();
	cout << "\n" << endl;	test_op06();
	cout << "\n" << endl;	test_op07();
//	cout << "\n" << endl;	test_op08();	Aborts, as it should!
	cout << "\n" << endl;	test_op09();
	cout << "\n" << endl;

	cout << "}" << endl;
}
