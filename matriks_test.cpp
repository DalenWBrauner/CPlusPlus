#include <iostream>
#include "matriks.cpp"

using namespace std;

void test01()
{
	
	matriks<float>		x;
	std::vector<float>	v = {1.0, 2.0, 3.0};
	
	cout << "test01" << endl;
	x = v;
	cout << "x = " << x << endl;
	cout << "end test01" << endl;
	return;
}

void test02()
{
	std::vector<double>	v = {1.0, 2.0, 3.0};
	matriks<double>		x(v);
	
	cout << "test02" << endl;
	cout << "x = " << x << endl;
	cout << "end test02" << endl;
	return;
}

void test03()
{
	std::vector<char>	v = { 'a', 'b', 'c'};
	matriks<char>		x(v), y;
	
	cout << "test03" << endl;
	y = x;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "end test03" << endl;
	return;
}

void test04()
{
	matriks<char>	x, y;
	
	cout << "test04" << endl;
	y = x;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "end test04" << endl;
	return;

}

void test05()
{
	std::vector<double> v = {1.0, 2.0, 3.0};
	matriks<double> x(v), y(v), z;
	cout << "test05" << endl;
	z = x + y;
	cout << "z = " << z << endl;
	cout << "end test05" << endl;
}

void test06()
{
	std::vector<double> v1 = {1.0, 2.3, 4.0};
	std::vector<double> v2 = {2.3, 4.5};
	matriks<double>	x(v1), y(v2), z;
	cout << "test06" << endl;
	z = x + y;
	cout << "z = " << z << endl;
	cout << "end test06" << endl;
}

void test07()
{
	std::vector<double> v1 = {1.0, 2.3, 4.0};
	std::vector<double> v2 = {1.3, 3.7, 4.5};
	matriks<double>	x(v1), y(v2), z1, z2;
	cout << "test07" << endl;
	z1 = x - y;
	z2 = y - x;
	cout << "x - y = " << z1 << endl;
	cout << "y - x = " << z2 << endl;
	cout << "end test07" << endl;
}

void test08()
{
	std::vector<double> v1 = {2.2, 1.1, 0.0};
	std::vector<double> v2 = {8.2, 7.1};
	matriks<double>	x(v1), y(v2), z1, z2;
	cout << "test08" << endl;
	z1 = x - y;
	z2 = y - x;
	cout << "x - y = " << z1 << endl;
	cout << "y - x = " << z2 << endl;
	cout << "end test08" << endl;
}

void test09()
{
	std::vector<double> v1 = {1.0, 2.3, 4.0};
	std::vector<double> v2 = {1.3, 3.7, 4.5};
	matriks<double>	x(v1), y(v2);
	double z1, z2;
	cout << "test09" << endl;
	z1 = x * y;
	z2 = y * x;
	cout << "x * y = " << z1 << endl;
	cout << "y * x = " << z2 << endl;
	cout << "end test09" << endl;
}

void test10()
{
	std::vector<double> v1 = {0.0, 0.0, 1.0};
	std::vector<double> v2 = {7.0, 8.0};
	matriks<double>	x(v1), y(v2);
	double z1, z2;
	cout << "test10" << endl;
	z1 = x * y;
	z2 = y * x;
	cout << "x * y = " << z1 << endl;
	cout << "y * x = " << z2 << endl;
	cout << "end test10" << endl;
}

void test11()
{
	std::vector<double> v1 = {777.0, 9.0, 0.1};
	std::vector<double> v2;
	matriks<double>	x(v1), y(v2);
	cout << "test11" << endl;
	cout << "x.isValid() " << x.isValid() << endl;
	cout << "y.isValid() " << y.isValid() << endl;
	cout << "end test11" << endl;
}

void test12()
{
	std::vector<double> v1 = {777.0, 9.0, 0.1};
	std::vector<double> v2;
	matriks<double>	x(v1), y(v2);
	cout << "test12" << endl;
	cout << "x.dimension() " << x.dimension() << endl;
	cout << "y.dimension() " << y.dimension() << endl;
	cout << "end test12" << endl;
}

void test13()
{
	std::vector<short> v1 = {4368, 4112, 4097};
	std::vector<short> v2 = {1, 257, 272};
	matriks<short>	x(v1), y(v2), z1, z2;
	cout << "test13" << endl;
	z1 = x & y;
	z2 = y & x;
	cout << "x & y = " << z1 << endl;
	cout << "y & x = " << z2 << endl;
	cout << "end test13" << endl;
}

void test14()
{
	std::vector<short> v1 = {1, 257, 272};
	std::vector<short> v2 = {4368, 4112};
	matriks<short>	x(v1), y(v2), z1, z2;
	cout << "test14" << endl;
	z1 = x & y;
	z2 = y & x;
	cout << "x & y = " << z1 << endl;
	cout << "y & x = " << z2 << endl;
	cout << "end test14" << endl;
}

void test15()
{
	std::vector<short> v1 = {1, 257, 272};
	std::vector<double> v2 = {43.8, 41.2};
	matriks<short>	x(v1);
	matriks<double>	y(v2);
	cout << "test15" << endl;
	x = y;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "end test15" << endl;
}

int main(int argc, char *argv[])
{
	int rc;
	
	cout << "main start\n" << endl;
	
	test01();	cout << endl;
	test02();	cout << endl;
	test03();	cout << endl;
	test04();	cout << endl;
	test05();	cout << endl;
	test06();	cout << endl;

	/* Dalen tests!

	It's worth noting that if v2 lacks a third value, it will take on
	whatever value it was assigned in a previous test function.
	Otherwise, it seems to take on the value of 6.

	i.e. If you run D_1() and then D_2(), v2[2] == 4.5.
	i.e. If you run D_2() and then D_1(), v2[2] == 6.0.
	This is not exclusive to D_1() and D_2(), but all 4 of my functions.

	Maybe even more fascinating is that not ALL of v2 takes on previous values;
	ONLY the omitted value.

	Any ideas why are posted on the next line.
	*/
	test07();	cout << endl;
	test08();	cout << endl;
	test09();	cout << endl;
	test10();	cout << endl;
	test11();	cout << endl;
	test12();	cout << endl;
	test13();	cout << endl;
	test14();	cout << endl;
	test15();	cout << endl;
}
