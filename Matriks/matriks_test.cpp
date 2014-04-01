#include <iostream>
#include "matriks.cpp"

using namespace std;

////////
// Matrix Tests
///
void test01()
{
	cout << "BEGIN:\ttest01()\t";
	cout << "Testing default matrix creation;" << endl;
	matriks<int> MX;
	cout << "matriks<int> MX;" << endl;
	cout << "END:\ttest01()" << endl;
	return;
}

void test02()
{
	cout << "BEGIN:\ttest02()\t";
	cout << "Testing .size();" << endl;
	matriks<int> MX;
	cout << "matriks<int> MX;" << endl;
	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;
	cout << "END:\ttest02()" << endl;
	return;
}

void test03()
{
	cout << "BEGIN:\ttest03()\t";
	cout << "Testing .hasElements();" << endl;
	cout << "matriks<int> MX;" << endl;
	matriks<int> MX;
	if (MX.hasElements())
	{ cout << "MX has elements!" << endl; }
	else
	{ cout << "MX has no elements!" << endl; }
	cout << "END:\ttest03()" << endl;
	return;
}

void test04()
{
	cout << "BEGIN:\ttest04()\t";
	cout << "Testing matriks creation with 1 element;" << endl;

	matriks<int> MX = 7;
	cout << "matriks<int> MX = 7;" << endl;

	cout << "MX is " << MX.size()[0] << " elements tall." << endl;
	cout << "MX is " << MX.size()[1] << " elements wide." << endl;

	if (MX.hasElements())
	{ cout << "MX has elements!" << endl; }
	else
	{ cout << "MX has no elements!" << endl; }

	cout << "END:\ttest04()" << endl;
	return;

}

void test05()
{
	cout << "BEGIN:\ttest05()\t";
	cout << "Testing matriks creation with 1 vector;" << endl;

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

	cout << "END:\ttest05()" << endl;
	return;
}

void test06()
{
	cout << "BEGIN:\ttest06()\t";
	cout << "Testing 3x4 matriks creation with composed vectors;" << endl;

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

	cout << "END:\ttest06()" << endl;
	return;
}

void test07()
{
	cout << "BEGIN:\ttest07()\t";
	cout << "Testing cout << matriks;" << endl;

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
	
	cout << "END:\ttest07()" << endl;
	return;
}

void test08()
{
	cout << "BEGIN:\ttest08()\t";
	cout << "Testing .resize();" << endl;

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

	cout << "END:\ttest08()" << endl;
	return;
}


////////
// Matrix Operation Tests
///
void test_op01()
{
	cout << "BEGIN:\ttest_op01()\t";
	cout << "Testing addition of two 3x2 matrikies;" << endl;

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
	cout << "END:\ttest_op01()" << endl;
	return;
}

void test_op02()
{
	cout << "BEGIN:\ttest_op02()\t";
	cout << "Testing subtraction of identical matrikies;" << endl;

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
	cout << "END:\ttest_op02()" << endl;
	return;
}

void test_op03()
{
	cout << "BEGIN:\ttest_op03()\t";
	cout << "Testing subtraction of different-sized matrikies;" << endl;

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

	cout << "END:\ttest_op03()" << endl;
	return;
}

void test_op04()
{
	cout << "BEGIN:\ttest_op04()\t";
	cout << "Testing scalar multiplication;" << endl;

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

	cout << "END:\ttest_op04()" << endl;
	return;
}

void test_op05()
{
	cout << "BEGIN:\ttest_op05()\t";
	cout << "Testing vektor multiplication;" << endl;

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

	cout << "END:\ttest_op05()" << endl;
	return;
}

void test_op06()
{
	cout << "BEGIN:\ttest_op06()\t";
	cout << "Testing vector multiplication;" << endl;

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

	cout << "END:\ttest_op06()" << endl;
	return;
}

int main()
{
	cout << "main()\n{";
	
	cout << endl;	test01();
	cout << endl;	test02();
	cout << endl;	test03();
	cout << endl;	test04();
	cout << endl;	test05();
	cout << endl;	test06();
	cout << endl;	test07();
	cout << endl;	test07();
	cout << endl;	test08();

	cout << endl;	test_op01();
	cout << endl;	test_op02();
//	cout << endl;	test_op03();	Aborts, as it should!
	cout << endl;	test_op04();
	cout << endl;	test_op05();
	cout << endl;	test_op06();

	cout << "}" << endl;
}
