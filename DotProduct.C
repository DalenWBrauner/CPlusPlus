#include<iostream>
using namespace std;

class Vector {

public:
	Vector(int s)
	:elem{new double[s]}, sz{s}
	{ for (int i=0; i!=s; ++i) elem[i]=0; }			// How to Construct: a Vector

	double& operator[](int i)
	{  return elem[i]; }							// How to Handle: the operator "[]"

	double operator*(Vector other)
	{
		double product = 0;
		for (int i=0; i!=sz; ++i)
		{ product += elem[i] * other[i]; }
		return product;
	}

	int size()
	{ return sz; }									// Define: Function "size()"

private:
	double* elem;	// pointer to the elements
	int sz;			// the number of elements
};

Vector Input_Vector()
{
	int s;
	cout << "How many elements are in your vector? ";
	cin >> s;
	Vector v(s);
	for (int i=0; i!=s; ++i)
		{
		cout<<"Please enter value #" << i << ": ";
		cin >>v[i];
		}
	return v;
}

void Dot_Product()
{
	double product;
	product = Input_Vector()*Input_Vector();
	cout << "Your dot product is " << product << ".\n";
}

int main()
{
	Dot_Product();
}
