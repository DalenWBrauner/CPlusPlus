#include <iostream>
#include <cmath>
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
		matriks();									// Create 0x0 Matrix
		matriks(const K &v);						// Create 1x1 Matrix
		matriks(const vector<K> &v);				// Create Mx1 Matrix
		matriks(const vector<vector<K>> &v);		// Create MxN Matrix

		// Operation methods
		matriks<K>&	operator=(const K &other);					// Assign 1x1 Matrix
		matriks<K>&	operator=(const vector<K> &other);			// Assign Mx1 Matrix 
		matriks<K>&	operator=(const vector<vector<K>> &other);	// Assign MxN Matrix

		bool operator==(K other);					// Compare as 1x1 Matrix
		bool operator==(vector<K> other);			// Compare as Mx1 Matrix
		bool operator==(vector<vector<K>> other);	// Compare as MxN Matrix
		bool operator==(matriks<K> other);			// Compare as expected

		vector<K>& operator[](unsigned int index);	// Get the vector at position index

		matriks<K>	operator+(matriks<K> &other);	// Matrix Addition
		matriks<K>	operator-(matriks<K> &other);	// Matrix Subtraction

		matriks<K>	operator*(K other);				// Scalar Multiplication
		double		operator*(vector<K> &other);	// Vector Multiplication
		double		operator*(vektor<K> &other);	// Vektor Multiplication
		matriks<K>	operator*(matriks<K> &other);	// Matrix Multiplication

		matriks<K>	operator&(const matriks<K> &other);			// Honestly, I've forgot.

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

		matriks<K> transpose()
		{
			vector<vector<K>> t;
			t.resize(M);
			for (auto i=0 ; i<M ; ++i)
			{
				t[i] = this->row(i);
			}
			matriks<K> output = t;
			return output;
		}
		// Row-Operation Methods
		void rowop_add(unsigned int row_scaled, unsigned int row_modified, K scalar)
		{
			assertNicely( (row_modified <= M), "row_modified does not exist.");
			assertNicely( (row_scaled <= M), "row_scaled does not exist.");
			for (auto i=0 ; i<N ; i++)
			{
				Mtrx[i][row_modified] += (Mtrx[i][row_scaled] * scalar);
			}
		}

		void rowop_swap(unsigned int row_1, unsigned int row_2)
		{
			assertNicely( (row_1 < M), "row_1 does not exist.");
			assertNicely( (row_2 < M), "row_2 does not exist.");
			{
				for (auto i=0 ; i<N ; i++)
				{
					K temp = Mtrx[i][row_1];
					Mtrx[i][row_1] = Mtrx[i][row_2];
					Mtrx[i][row_2] = temp;
				}
			}
		}

		void rowop_scale(unsigned int row, K constant)
		{
			assertNicely( (row <= M), "row does not exist.");
			for (auto i=0 ; i<N ; i++)
			{
				Mtrx[i][row] *= constant;
			}
		}

		matriks<float> reducedEchelon(float zero_threshold = 0.000001, bool calc_inverse = false)
		/* Returns the reduced echelon form of the matrix.
		   Any absolute value less than the 'zero_threshold' is considered zero. */
//		Feel free to use the commented-out cout statements for debugging!
		{
			matriks<float> rEch = Mtrx;
			matriks<float> invrs;
			invrs.becomeIdentity(N);

			unsigned int r=0, v=0;
			while ( (v<N) and (r<M) )
			{
				if (calc_inverse) { cout << invrs << "\n"; }
				cout << rEch << "\n";
				cout << v << ", " << r << "\n";
				cout << "Is the value 1?\t";
				if (rEch[v][r] == 1)
				{
					cout << "TRUE. 0\n";
					cout << "Use rowAdd to reduce ALL OTHER values in the vector to 0.\n";
					for (auto i=0 ; i<M ; i++)
					{
						if (i != r)
						{
							cout << "Adding row " << r << " to row " << i << " (* " << rEch[v][i] << ")\n";
							if (calc_inverse) { invrs.rowop_add(r, i, -rEch[v][i]); }
							rEch.rowop_add(r, i, -rEch[v][i]);
						}
					}
					cout << "Repeat for next row/vector.\n";
					v++;
					r++;
				}
				else
				{
					cout << "FALSE. 1\n";
					cout << "Is it 0?.\t";
					//if (rEch[v][r] == 0)
					// Gotta do this madness, otherwise decimal errors get rowScaled to 1.
					if ( abs( rEch[v][r] ) < zero_threshold)
					{
						cout << "TRUE. 2\n";
						cout << "Are any BELOW values in the vector nonzero?\t";
						unsigned long Q;
						for (Q=r+1; Q<M ; Q++)
						{
							//if (rEch[v][Q] != 0)
							// Gotta do this madness, otherwise decimal errors get rowScaled to 1.
							if ( abs( rEch[v][Q] ) > zero_threshold)
							{
								cout << "TRUE. 3\n";
								cout << "Swap, rowScale to 1.\n";
								if (calc_inverse) { invrs.rowop_swap(r, Q); }
								rEch.rowop_swap(r, Q);
								if (calc_inverse) { invrs.rowop_scale(r, 1.0/rEch[v][r]); }
								rEch.rowop_scale(r, 1.0/rEch[v][r]);
								Q = M+8;	// Only possible if we've found a nonzero.
							}
							else { cout << "NOPE. -1\t"; }
						}
						if (Q != M+9)	// i.e. only possible if we've NOT found a nonzero,
						{
							cout << "FALSE. 4\n";
							cout << "Repeat for next vector.\n";
							v++;
						}
					}
					else
					{
						cout << "FALSE. 5\n";
						cout << "rowScale it to 1.\n";
						if (calc_inverse) { invrs.rowop_scale(r, 1.0/rEch[v][r]); }
						rEch.rowop_scale(r, 1.0/rEch[v][r]);
					}
				}
			}
			if (calc_inverse)	{ return invrs; }
			return rEch;
		}

		// Inverse Methods
		bool isSquare()
		{ return (hasElements() and ( M == N ) ); }

		int determinant()
		/* Unfinished */
		{
			assertNicely(
				isSquare(),
				"Matrikies currently can only calculate determinants if square."
				);
			return (Mtrx[0][0] * Mtrx[1][1]) - (Mtrx[0][1] * Mtrx[1][0]);
		}

		void becomeIdentity(unsigned int v)
		{
			this->resize(v,v);
			for (auto i=0 ; i<v ; i++)
			{
				for (auto j=0 ; j<v ; j++)
				{
					if (i==j)	{ Mtrx[i][j] = 1; }
					else		{ Mtrx[i][j] = 0; }
				}
			}
		}

		unsigned int isIdentity()
		{
			if (!isSquare()) { return false; }
			for (auto i=0 ; i<M ; i++)
			{
				for (auto j=0 ; j<N ; j++)
				{
					if (i==j)	{ if(Mtrx[i][j] != 1) { return false; } }
					else		{ if(Mtrx[i][j] != 0) { return false; } }
				}
			}
			return M;
		}

		bool isInverseOf(matriks<K> other)
		{
			if (!isSquare())			{ return false; }
			if (!other.isSquare())		{ return false; }
			if (N != other.N)			{ return false; }

			matriks<K> me = this->Mtrx;
			matriks<K> I;
			I.becomeIdentity(N);
			return (other * me == I);
		}

		matriks<K> inverse()
		{
			matriks<K> Original = Mtrx;
			return Original.reducedEchelon(0.000001, true);
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
{
	Mtrx = v;
	N = Mtrx.size();
	M = Mtrx[0].size();
	for (auto i=1 ; i<N ; i++)
	{
		assertNicely(
			(Mtrx[i].size() == M),
			"The vectors in a matrix must all be of equal length."
			);
	}
}

////////
// Standard Operation Methods
///

//		bool operator==(K &other);					// Compare as 1x1 Matrix
//		bool operator==(vector<K> &other);			// Compare as Mx1 Matrix
//		bool operator==(vector<vector<K>> &other);	// Compare as MxN Matrix
//		bool operator==(matriks<K> &other);			

template<typename K>
bool matriks<K>::operator==(K other)
/* Compares 'other' as a 1x1 Matrix */
{
	matriks<K> dummy = other;
	return matriks<K>::operator==(dummy);
}

template<typename K>
bool matriks<K>::operator==(vector<K> other)
/* Compares 'other' as an Mx1 Matrix */
{
	matriks<K> dummy = other;
	return matriks<K>::operator==(dummy);
}

template<typename K>
bool matriks<K>::operator==(vector<vector<K>> other)
/* Compares 'other' as an MxN Matrix */
{
	matriks<K> dummy = other;
	return matriks<K>::operator==(dummy);
}

template<typename K>
bool matriks<K>::operator==(matriks<K> other)
/* Assures both matrikies are the same size and contain the same elements */
{
	if (other.N != N) { return false; }
	if (other.M != M) { return false; }
	for (auto i=0 ; i<N ; i++)
	{ if (Mtrx[i] != other[i]) { return false; } }
	return true;
}

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
