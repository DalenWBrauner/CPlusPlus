#include <iostream>
#include <vector>

template<typename T>
class vektor
{
	private:
		std::vector<T>	x;
	public:
		// Creation methods
		vektor();
		vektor(const std::vector<T> &v);
		~vektor();
		// Operation methods
		vektor<T>&	operator=(const std::vector<T> &o);
		vektor<T>	operator+(const vektor<T> &o);
		vektor<T>	operator-(const vektor<T> &o);
		double		operator*(const vektor<T> &o);		// Vector Multiplication
		vektor<T>	operator*(const T &o);				// Scalar Multiplication
		vektor<T>	operator&(const vektor<T> &o);

		unsigned int dimension()
		{ return x.size(); }

		bool isValid()
		{ return (x.size() == 0); }
		

	friend std::ostream& operator<<(std::ostream& s, vektor<T> &v) {
		int i;

		if(v.x.size() > 0) {
			s << "<";
			for(i=0; i<v.x.size() -1; i++) {
				s << v.x[i] << ",";
			}
			s << v.x[i] << ">";
			return s;
		} else {
			s << "<NO_SIZE>";
			return(s);
		}
	}

	operator std::vector<T>() const
	{ return x; }

	template<typename Q>
	vektor<T>& operator=(const vektor<Q> &o)
	{
		std::vector<Q> v;

		v = (std::vector<Q>)o;
		x.resize(v.size());
		for(auto i=0; i<v.size(); i++)
			{ x[i] = (T)v[i]; }
		return(*this);
	}
};

template<typename T>
vektor<T>::vektor()
{
	std::cout << "Construct vektor" << std::endl;
	return;
}

template<typename T>
vektor<T>::vektor(const std::vector<T> &o)
{
	std::cout << "Construct vektor from vector<T>" << std::endl;
	x = o;
	return;
}

template<typename T>
vektor<T>::~vektor()
{
	std::cout << "Destruct vektor" << std::endl;
	return;
}

template<typename T>
vektor<T>& vektor<T>::operator=(const std::vector<T> &o)
{
	x = o;
	std::cout << "assign vektor" << std::endl;
	return(*this);
}

template <typename T>
vektor<T> vektor<T>::operator+(const vektor<T> &o)
{
	vektor<T>		r;
	std::vector<T>	y;

	y.resize(x.size());
	for(int i = 0; i< x.size(); i++) {
		y[i] = x[i] + o.x[i];
	}
	r = y;
	return(r);
}

template <typename T>
vektor<T> vektor<T>::operator-(const vektor<T> &o)
{
	vektor<T>		r;
	std::vector<T>	y;

	y.resize(x.size());
	for(int i = 0; i< x.size(); i++) {
		y[i] = x[i] - o.x[i];
	}
	r = y;
	return(r);
}

template <typename T>
double vektor<T>::operator*(const vektor<T> &o)
/* Vector Multiplication */
{
	double dotProduct = 0;

	for (int i=0; i< x.size(); i++) {
		dotProduct += x[i] * o.x[i];
	}

	return dotProduct;
}

template <typename T>
vektor<T> vektor<T>::operator*(const T &o)
/* Scalar Multiplication */
{
	for (int i=0; i< x.size(); i++) {
		x[i] *= o;
	}
	return (*this);
}

template <typename T>
vektor<T> vektor<T>::operator&(const vektor<T> &o)
{
	vektor<T>		r;
	std::vector<T>	y;

	y.resize(x.size());
	for(int i = 0; i< x.size(); i++) {
		y[i] = x[i] & o.x[i];
	}
	r = y;
	return(r);
}
