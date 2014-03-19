#include <iostream>
#include <vector>
#include "vektor.cpp"
using namespace std;

template<typename K>
class matriks
{
	private:
		vector<vector<K>>		Mtrx;
		unsigned int			M;		// Column Length	(or # of Rows)
		unsigned int			N;		// Row Length		(or # of Cols)

	public:
		// Creation methods
		matriks();												// Create 0x0 Matrix
		matriks(const K &v);									// Create 1x1 Matrix
		matriks(const vector<K> &v);							// Create Mx1 Matrix
		matriks(const vector<vector<K>> &v);					// Create MxN Matrix

		// Operation methods
		matriks<K>&	operator=(const K &other);					// Assign 1x1 Matrix
		matriks<K>&	operator=(const vector<K> &other);			// Assign Mx1 Matrix 
		matriks<K>&	operator=(const vector<vector<K>> &other);	// Assign MxN Matrix

		matriks<K>&	operator==(const K &other);					// Compare as 1x1 Matrix
		matriks<K>&	operator==(const vector<K> &other);			// Compare as Mx1 Matrix
		matriks<K>&	operator==(const vector<vector<K>> &other);	// Compare as MxN Matrix

		matriks<K>	operator+(matriks<K> &other);			// Matrix Addition
		matriks<K>	operator-(matriks<K> &other);			// Matrix Subtraction

		matriks<K>	operator*(K &other);					// Scalar Multiplication
		double		operator*(vector<K> &other);			// Vector Multiplication
		double		operator*(vektor<K> &other);			// Vektor Multiplication
		matriks<K>	operator*(matriks<K> &other);			// Matrix Multiplication

		matriks<K>	operator&(const matriks<K> &other);

		// Other methods
		vector<unsigned int> size()
		{ return {M, N}; }

		bool hasElements()
		{ return (( M != 0) and (N != 0)); }

/*
		void resize(unsigned int m, unsigned int n)
		{
		}
*/

		friend ostream& operator<<(ostream& s, matriks<K> &MX)
		{
			for (auto m=0 ; m<MX.M ; m++) {
				s << "\n[\t";
				for (auto n=0 ; n<MX.N ; n++) {
					s << MX.Mtrx[n][m];
					s << "\t";
				}
			s << "]";
			}
			return(s);
		}


};

//
////
////// Creation Methods
template<typename K>
matriks<K>::matriks()
/* Create 0x0 Matrix */
{
	M = 0;
	N = 0;
}

template<typename K>
matriks<K>::matriks(const K &v)
/* Create 1x1 Matrix */
{
	Mtrx = {{v}};
	M = Mtrx[0].size();
	N = Mtrx.size();
}

template<typename K>
matriks<K>::matriks(const vector<K> &v)
/* Create Mx1 Matrix */
{
	Mtrx = {v};
	M = Mtrx[0].size();
	N = Mtrx.size();
}

template<typename K>
matriks<K>::matriks(const vector<vector<K>> &v)
/* Create MxN Matrix */
{
	Mtrx = v;
	M = Mtrx[0].size();
	N = Mtrx.size();
}


//
////
////// Operation Methods
template<typename K>
matriks<K> matriks<K>::operator+(matriks<K> &other)
/* Matrix Addition */
{
	// First assure they are the same size
	if ((M != other.size()[0]) or (N != other.size()[1]))
	{return 1;}

	vector<vector<K>> New;

	for (auto n=0 ; n<N ; n++) {
		vector<K> v;
		for (auto m=0 ; m<M ; m++) {
			K sum = Mtrx[n][m] + other.Mtrx[n][m];
			v.push_back(sum);
		}
		New.push_back(v);
	}
	return New;
}

template<typename K>
matriks<K> matriks<K>::operator-(matriks<K> &other)
/* Matrix Subtraction */
{
	// First assure they are the same size
	if ((M != other.size()[0]) or (N != other.size()[1]))
	{return 1;}

	vector<vector<K>> New;

	for (auto n=0 ; n<N ; n++)
	{
		vector<K> v;
		for (auto m=0 ; m<M ; m++)
		{
			K dif = Mtrx[n][m] - other.Mtrx[n][m];
			v.push_back(dif);
		}
		New.push_back(v);
	}
	return New;
}

template<typename K>
matriks<K> matriks<K>::operator*(K &other)
/* Scalar Multiplication */
{
	vector<vector<K>> New = Mtrx;
	for (auto n=0 ; n<N ; n++) 
	{
		for (auto m=0 ; m<M ; m++)
			{ New[n][m] *= other; }
	}
	matriks<K> result = New;
	return result;
}

//		double		operator*(const vector<K> &other);			Vector Multiplication
//		double		operator*(const vektor<K> &other);			Vektor Multiplication
//		matriks<K>	operator*(const matriks<K> &other);			Matrix Multiplication
