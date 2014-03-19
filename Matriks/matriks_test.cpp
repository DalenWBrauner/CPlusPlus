#include <iostream>
#include "matriks.cpp"

using namespace std;

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
	
	cout << "END:\ttest06()" << endl;
	return;
}

void test08()
{
	cout << "BEGIN:\ttest08()\t";
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
	cout << "END:\ttest08()" << endl;
	return;
}

void test09()
{
	cout << "BEGIN:\ttest09()\t";
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
	cout << "END:\ttest09()" << endl;
	return;
}


int main()
{
	cout << "main()\n{" << endl;
	
	test01();	cout << endl;
	test02();	cout << endl;
	test03();	cout << endl;
	test04();	cout << endl;
	test05();	cout << endl;
	test06();	cout << endl;
	test07();	cout << endl;
	test08();	cout << endl;
	test09();	cout << endl;

	cout << "}" << endl;
}
