#include <iostream>
#include <vector>
#include "vektor.cpp"
using namespace std;

template<typename K>
class matriks
{
	private:
		vector<vector<K>>	Mtrx;
		unsigned int		M;
		unsigned int		N;

	public:
		// Creation methods
		matriks();
		matriks(const vector<K> &v);
		matriks(const vector<vector<K>> &v);
		~matriks();
		// Operation methods
		matriks<K>&	operator=(const <K> &other);				// Create 1x1 Matrix
		matriks<K>&	operator=(const vector<K> &other);			// Create Mx1 Matrix 
		matriks<K>&	operator=(const vector<vector<K>> &other);	// Create MxN Matrix

		matriks<K>&	operator==(const <K> &other);				// Compare as 1x1 Matrix
		matriks<K>&	operator==(const vector<K> &other);			// Compare as Mx1 Matrix
		matriks<K>&	operator==(const vector<vector<K>> &other);	// Compare as MxN Matrix

		matriks<K>	operator+(const matriks<K> &other);			// Matrix Addition
		matriks<K>	operator-(const matriks<K> &other);			// Matrix Subtraction

		matriks<K>	operator*(const <K> &other);				// Scalar Multiplication
		double		operator*(const vector<K> &other);			// Vector Multiplication
		matriks<K>	operator*(const matriks<K> &other);			// Matrix Multiplication
		matriks<K>	operator&(const matriks<K> &other);

		unsigned int dimension()
		{ return x.size(); }

		bool isValid()
		{ return (x.size() == 0); }
		

	friend std::ostream& operator<<(std::ostream& s, matriks<K> &v) {
		int i;

		if(v.x.size() > 0) {
			s << "(";
			for(i=0; i<v.x.size() -1; i++) {
				s << v.x[i] << ", ";
			}
			s << v.x[i] << ")";
			return s;
		} else {
			s << "<NO_SIZE>";
			return(s);
		}
	}

	operator std::vector<K>() const
	{ return x; }

	template<typename Q>
	matriks<K>& operator=(const matriks<Q> &o)
	{
		std::vector<Q> v;

		v = (std::vector<Q>)o;
		x.resize(v.size());
		for(auto i=0; i<v.size(); i++)
			{ x[i] = (K)v[i]; }
		return(*this);
	}
};

template<typename K>
matriks<K>::matriks()
{
	std::cout << "Construct matriks" << std::endl;
	return;
}

template<typename K>
matriks<K>::matriks(const std::vector<K> &o)
{
	std::cout << "Construct matriks from vector<K>" << std::endl;
	x = o;
	return;
}

template<typename K>
matriks<K>::~matriks()
{
	std::cout << "Destruct matriks" << std::endl;
	return;
}

template<typename K>
matriks<K>& matriks<K>::operator=(const std::vector<K> &o)
{
	x = o;
	std::cout << "assign matriks" << std::endl;
	return(*this);
}

template <typename K>
matriks<K> matriks<K>::operator+(const matriks<K> &o)
{
	matriks<K>		r;
	std::vector<K>	y;

	y.resize(x.size());
	for(int i = 0; i< x.size(); i++) {
		y[i] = x[i] + o.x[i];
	}
	r = y;
	return(r);
}

template <typename K>
matriks<K> matriks<K>::operator-(const matriks<K> &o)
{
	matriks<K>		r;
	std::vector<K>	y;

	y.resize(x.size());
	for(int i = 0; i< x.size(); i++) {
		y[i] = x[i] - o.x[i];
	}
	r = y;
	return(r);
}

template <typename K>
double matriks<K>::operator*(const matriks<K> &o)
{
	double dotProduct = 0;

	for (int i=0; i< x.size(); i++) {
		dotProduct += x[i] * o.x[i];
	}

	return dotProduct;
}

template <typename K>
matriks<K> matriks<K>::operator&(const matriks<K> &o)
{
	matriks<K>		r;
	std::vector<K>	y;

	y.resize(x.size());
	for(int i = 0; i< x.size(); i++) {
		y[i] = x[i] & o.x[i];
	}
	r = y;
	return(r);
}
