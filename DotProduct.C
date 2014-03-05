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
		/* I want to throw in
		if (sz != other.size()) throw some_error;
		at some point, but what few error types I've tried ended poorly. */
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

double Dot_Product(int s)
{
	Vector v1(s), v2(s);
	for (int i=0; i!=v1.size(); ++i) {
		cout<<"Please enter in value #" << i << " for the 1st vector: ";
		cin >>v1[i];
		}

	for (int i=0; i!=v2.size(); ++i) {
		cout<<"Please enter in value #" << i << " for the 2nd vector: ";
		cin >>v2[i];
		}

	double product = 0;
	for (int i=0; i!=s; ++i)
		product += v1[i] * v2[i];

	return product;
}

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

int main()
{
	/*
	Wa-hey! This brings up an interesting error.
	I think I understand the need for pointers.
	Vector *v1, *v2;
	v1 = Input_Vector();
	v2 = Input_Vector();
	double product;
	product = v1*v2;
	*/
	double product;
	product = Input_Vector()*Input_Vector();
	cout << "Your dot product is " << product << ".\n";
}
