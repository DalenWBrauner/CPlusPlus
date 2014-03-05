#include<iostream>
using namespace std;

class Vector {

public:
	Vector(int s) :elem{new double[s]}, sz{s}
	{
		for (int i=0; i!=s; ++i) elem[i]=0;
	}												// How to Construct: a Vector

	~Vector() { delete[] elem; }					// How to DECONSTRUCT RAWR

	double& operator[](int i)
	{  return elem[i]; }							// How to Handle: the operator "[]"

/*
	double operator*(Vector other)
	{
		//if (sz != other.size()) throw some_error;
		double product = 0;
		for (int i=0; i!=sz; ++i)
			product += elem[i] * other[i];
		return product;
	}
*/

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

int main()
{
	int size;
	double product;
	cout << "How many elements are in your 2 vectors? ";
	cin >> size;
	product = Dot_Product(size);
	cout << "Their Dot Product is " << product << ".\n";
/*
	Vector v1(4), v2(4);
	for (int i=1; i!=5; ++i) {
		v1[i-1] = i;
		v2[i-1] = i;
	}
	cout << "So far so good.\n";
	double value = v1*v2;
	cout << value;
*/
}
