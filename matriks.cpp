#include <iostream>
#include <vector>

template<typename K>
class matriks
{
	private:
		std::vector<K>	x;
	public:
		matriks();
		matriks(const std::vector<K> &v);
		~matriks();
		matriks<K>&	operator=(const std::vector<K> &o);
		matriks<K>	operator+(const matriks<K> &o);
		matriks<K>	operator-(const matriks<K> &o);
		double		operator*(const matriks<K> &o);
		matriks<K>	operator&(const matriks<K> &o);

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
