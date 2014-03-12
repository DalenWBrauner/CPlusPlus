#include <iostream>
#include "conlen_vektor.hpp"

using namespace std;

void test1()
{
	
	vektor<float>		x;
	std::vector<float>	v = {1.0, 2.0, 3.0};
	
	cout << "test1" << endl;
	x = v;
	cout << "x = " << x << endl;
	cout << "end test1" << endl;
	return;
}

void test2()
{
	std::vector<double>	v = {1.0, 2.0, 3.0};
	vektor<double>		x(v);
	
	cout << "test2" << endl;
	cout << "x = " << x << endl;
	cout << "end test2" << endl;
	return;
}

void test3()
{
	std::vector<char>	v = { 'a', 'b', 'c'};
	vektor<char>		x(v), y;
	
	cout << "test3" << endl;
	y = x;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "end test3" << endl;
	return;

}

void test4()
{
	vektor<char>	x, y;
	
	cout << "test4" << endl;
	y = x;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "end test4" << endl;
	return;

}

void test5()
{
	std::vector<double> v = {1.0, 2.0, 3.0};
	vektor<double> x(v), y(v), z;
	cout << "test5" << endl;
	z = x + y;
	cout << "z = " << z << endl;
	cout << "end test5" << endl;
}

void test6()
{
	std::vector<double> v1 = {1.0, 2.3, 4.0};
	std::vector<double> v2 = {2.3, 4.5};
	vektor<double>	x(v1), y(v2), z;
	cout << "test6" << endl;
	z = x + y;
	cout << "z = " << z << endl;
	cout << "end test6" << endl;
}

void testD_01()
{
	std::vector<double> v1 = {1.0, 2.3, 4.0};
	std::vector<double> v2 = {1.3, 3.7, 4.5};
	vektor<double>	x(v1), y(v2), z1, z2;
	cout << "testD_01" << endl;
	z1 = x - y;
	z2 = y - x;
	cout << "x - y = " << z1 << endl;
	cout << "y - x = " << z2 << endl;
	cout << "end testD_01" << endl;
}

void testD_02()
{
	std::vector<double> v1 = {2.2, 1.1, 0.0};
	std::vector<double> v2 = {8.2, 7.1};
	vektor<double>	x(v1), y(v2), z1, z2;
	cout << "testD_02" << endl;
	z1 = x - y;
	z2 = y - x;
	cout << "x - y = " << z1 << endl;
	cout << "y - x = " << z2 << endl;
	cout << "end testD_02" << endl;
}

void testD_03()
{
	std::vector<double> v1 = {1.0, 2.3, 4.0};
	std::vector<double> v2 = {1.3, 3.7, 4.5};
	vektor<double>	x(v1), y(v2);
	double z1, z2;
	cout << "testD_03" << endl;
	z1 = x * y;
	z2 = y * x;
	cout << "x * y = " << z1 << endl;
	cout << "y * x = " << z2 << endl;
	cout << "end testD_03" << endl;
}

void testD_04()
{
	std::vector<double> v1 = {0.0, 0.0, 1.0};
	std::vector<double> v2 = {7.0, 8.0};
	vektor<double>	x(v1), y(v2);
	double z1, z2;
	cout << "testD_04" << endl;
	z1 = x * y;
	z2 = y * x;
	cout << "x * y = " << z1 << endl;
	cout << "y * x = " << z2 << endl;
	cout << "end testD_04" << endl;
}

void testD_05()
{
	std::vector<double> v1 = {777.0, 9.0, 0.1};
	std::vector<double> v2;
	vektor<double>	x(v1), y(v2);
	cout << "testD_05" << endl;
	cout << "x.isValid() " << x.isValid() << endl;
	cout << "y.isValid() " << y.isValid() << endl;
	cout << "end testD_05" << endl;
}

void testD_06()
{
	std::vector<double> v1 = {777.0, 9.0, 0.1};
	std::vector<double> v2;
	vektor<double>	x(v1), y(v2);
	cout << "testD_06" << endl;
	cout << "x.dimension() " << x.dimension() << endl;
	cout << "y.dimension() " << y.dimension() << endl;
	cout << "end testD_06" << endl;
}

void testD_07()
{
	std::vector<short> v1 = {4368, 4112, 4097};
	std::vector<short> v2 = {1, 257, 272};
	vektor<short>	x(v1), y(v2), z1, z2;
	cout << "testD_07" << endl;
	z1 = x & y;
	z2 = y & x;
	cout << "x & y = " << z1 << endl;
	cout << "y & x = " << z2 << endl;
	cout << "end testD_07" << endl;
}

void testD_08()
{
	std::vector<short> v1 = {1, 257, 272};
	std::vector<short> v2 = {4368, 4112};
	vektor<short>	x(v1), y(v2), z1, z2;
	cout << "testD_08" << endl;
	z1 = x & y;
	z2 = y & x;
	cout << "x & y = " << z1 << endl;
	cout << "y & x = " << z2 << endl;
	cout << "end testD_08" << endl;
}

void testD_09()
{
	std::vector<short> v1 = {1, 257, 272};
	std::vector<double> v2 = {43.8, 41.2};
	vektor<short>	x(v1);
	vektor<double>	y(v2);
	cout << "testD_09" << endl;
	x = y;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "end testD_09" << endl;
}

int main(int argc, char *argv[])
{
	int rc;
	
	cout << "main start\n" << endl;
	
	test1();
	cout << endl;
	test2();
	cout << endl;
	test3();
	cout << endl;
	test4();
	cout << endl;
	test5();
	cout << endl;
	test6();

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
	cout << endl;
	testD_01();
	cout << endl;
	testD_02();
	cout << endl;
	testD_03();
	cout << endl;
	testD_04();
	cout << endl;
	testD_05();
	cout << endl;
	testD_06();
	cout << endl;
	testD_07();
	cout << endl;
	testD_08();
	cout << endl;
	testD_09();
	
	return(0);
}
