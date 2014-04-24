#include <iostream>

#include "Toe.cpp"
#include "bt.cpp"
#include "tree.cpp"

using namespace std;

// ???
typedef tree<ttt<>, hash_ttt<>> tttTree;
/*
void fillTree2(tttTree &t, int depth = 0)
{
	ttt<>	game, tmpGame;
	shared_ptr<tttTree>	newTree;
	int rc;
	static int counter = 0;
	
	for(auto i : t) {
		if(i.first.gameWon() == 0)
		for(auto j = 1; j <= 9; j++) {
			tmpGame = i.first;
			rc = tmpGame.move(j);
			if(rc == 0) { i.second->insert(tmpGame); }
		}
		fillTree2(*i.second, depth+1);
	}
	return;
}
*/

void T01()
{
}


int main()
{
//	T01()
}
