#include <iostream>
#include <memory>
#include <utility>
#include <unordered_map>
using namespace std;

template<typename T, typename H>
class tree;

template<typename T, typename H>
class tree : public unordered_map<T, shared_ptr<tree<T, H>>, H>
{
	using unordered_map<T, shared_ptr<tree<T, H>>, H>::insert;
	public:
	void insert(const T &d);
};

template<typename T, typename H>
void tree<T, H>::insert(const T &d)
{
	this->insert(pair<T, shared_ptr<tree<T, H>>>(d, make_shared<tree<T, H>>()));
	return;
}

template<typename T, typename H>
ostream& operator<<(ostream& s, const tree<T, H> &t);

template<typename T, typename H>
ostream& operator<<(ostream& s, const tree<T, H> &t)
{
	for(auto i : t) {
		s << i.first << "\n";
		s << *i.second << "\n";
	}
return s;
}
