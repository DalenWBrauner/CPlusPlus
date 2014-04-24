#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>
#include <memory>

#include "Toe.cpp"
using namespace std;

typedef vector<vector<char>>	Board;

class boardTree;

ostream& operator<<(ostream& s, boardTree &b);

class boardTree {
	private:
		ttt<0>	node;
		vector<boardTree>	leafs;
	
	public:
		boardTree();
		boardTree(const ttt<0> &b);
		~boardTree();
		void setBoard(const ttt<0> &b);
		ttt<0> getBoard();
		boardTree *insertBoard(const ttt<0> &b);
	
	friend ostream& operator<<(ostream& s, boardTree &b);
	
};

boardTree::boardTree()
{
	return;
}

boardTree::boardTree(const ttt<0> &b)
	: boardTree()
{
	node = b;
	return;
}

boardTree::~boardTree()
{
	return;
}

void boardTree::setBoard(const ttt<0> &b)
{
	node = b;
	return;
}

boardTree *boardTree::insertBoard(const ttt<0> &b)
{
	boardTree	bt(b);
	leafs.push_back(bt);
	return(&(leafs[leafs.size()-1]));
}
ttt<0> boardTree::getBoard()
{
	return(node);
}

ostream& operator<<(ostream& s, boardTree &b)
{
	ttt<>	*g;
	g = new ttt<>(b.node);
	
	s << *g;
	for(auto &i : b.leafs) { s << i; }
	return s;
}
