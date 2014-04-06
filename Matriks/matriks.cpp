#include <iostream>
#include <vector>
#include "vektor.cpp"
#include "../TooNice.cpp"
using namespace std;

template<typename K>
class matriks
{
	private:
		vector<vector<K>>		Mtrx;	// Vector containing the Columns of the Matrix
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

		vector<K>& operator[](unsigned int index);				// Get the vector at position index

		matriks<K>	operator+(matriks<K> &other);			// Matrix Addition
		matriks<K>	operator-(matriks<K> &other);			// Matrix Subtraction

		matriks<K>	operator*(K other);						// Scalar Multiplication
		double		operator*(vector<K> &other);			// Vector Multiplication
		double		operator*(vektor<K> &other);			// Vektor Multiplication
		matriks<K>	operator*(matriks<K> &other);			// Matrix Multiplication

		matriks<K>	operator&(const matriks<K> &other);		// Honestly, I've forgot.

		// Allows iostream output via '<<'
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

		// Other methods
		vector<unsigned int> size()
		{ return {M, N}; }

		bool hasElements()
		{ return (( M != 0) and (N != 0)); }

		void resize(unsigned int new_m, unsigned int new_n)
		{
			Mtrx.resize(new_n);
			N = new_n;
			M = new_m;
			for (auto whichVec=0 ; whichVec<N ; whichVec++)
			{
				Mtrx[whichVec].resize(new_m);
			}
		}

		vektor<K> row(unsigned int index)
		{
			vektor<K> r;
			for (auto n=0 ; n<N ; n++)
			{
				r.push_back(Mtrx[n][index]);
			}
			return r;
		}

};

////////
// Creation Methods
///
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
// WARNING: ALLOWS CREATION OF MATIKS WITH VECTORS OF INEQUAL SIZES
{
	Mtrx = v;
	M = Mtrx[0].size();
	N = Mtrx.size();
}


////////
// Standard Operation Methods
///
template<typename K>
vector<K>& matriks<K>::operator[](unsigned int index)
/* Get the vector at position index */
{
	return Mtrx[index];
}

////////
// Mathematical Operation Methods
///
template<typename K>
matriks<K> matriks<K>::operator+(matriks<K> &other)
/* Matrix Addition */
{
	// First assert they are the same size
	assertNicely(
		( (M == other.size()[0]) and (N == other.size()[1]) ),
		"Matriks must be of equal size before addition."
	);

	matriks<K> Result;
	Result.resize(M,N);

	for (auto n=0 ; n<N ; n++) {
		for (auto m=0 ; m<M ; m++) {
			Result[n][m] = Mtrx[n][m] + other[n][m];
		}
	}
	return Result;
}

template<typename K>
matriks<K> matriks<K>::operator-(matriks<K> &other)
/* Matrix Subtraction */
{
	// First assert they are the same size
	assertNicely(
		( (M == other.size()[0]) and (N == other.size()[1]) ),
		"Matriks must be of equal size before subtraction."
	);

	matriks<K> Result;
	Result.resize(M,N);

	for (auto n=0 ; n<N ; n++) {
		for (auto m=0 ; m<M ; m++) {
			Result[n][m] = Mtrx[n][m] - other[n][m];
		}
	}
	return Result;
}

template<typename K>
matriks<K> matriks<K>::operator*(K other)
/* Scalar Multiplication */
{
	matriks<K> Result;
	Result.resize(M,N);

	for (auto n=0 ; n<N ; n++) {
		for (auto m=0 ; m<M ; m++)
			{ Result[n][m] = Mtrx[n][m] * other; }
	}
	return Result;
}

template<typename K>
double matriks<K>::operator*(vector<K> &other)
/* Vector Multiplication */
{
	vektor<K> vikky = other;
	return matriks<K>::operator*(vikky);
}

template<typename K>
double matriks<K>::operator*(vektor<K> &other)
/* Vektor Multiplication */
{
	// First assert they are properly sized
	assertNicely(
		(M == other.dimension()),
		"A Vector must be of equal size to the Matrik's columns before multiplication."
	);

	double Grand_Sum = 0.0;
	for (auto col=0 ; col<N ; col++)
		{
			vektor<K> vikky = Mtrx[col];
			Grand_Sum += vikky * other;
		}
	return Grand_Sum;
}

template<typename K>
matriks<K> matriks<K>::operator*(matriks<K> &other)
/* Matrix Multiplication*/
{
	// First assert 
	assertNicely(
		(N == other.M),
		"A Matrix 'A' must have the same number of rows as a Matrix 'B' has columns before A*B."
	);

	matriks<K> Output;
	Output.resize(M,other.N);

	// multiply each row in 'self' by each vector in 'other'
	for (auto n=0 ; n<other.N ; ++n)
	{
		for (auto m=0 ; m<M ; ++m)
		{
			vektor<K> A = other.Mtrx[n];
			vektor<K> B = this->row(m);
			Output.Mtrx[n][m] += A * B;
		}
	}

	return Output;
}
