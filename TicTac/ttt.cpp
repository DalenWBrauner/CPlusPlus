#ifndef TTT_HPP
#define TTT_HPP

#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef vector<vector<char>> tttBoard;

template<int DEBUG=0>
class ttt;

template<int DEBUG=0>
class hash_ttt;

template<int DEBUG=0>
ostream& operator<<(ostream& s, const ttt<DEBUG> &t);

template<int DEBUG>
class ttt {
	private:
		/* board[col][row] */
		vector<vector<char>>	board;
		// vector<vector<vector<char>>> history;
		
		vector<string>	player;
		int turn = 0;
		static mt19937	mt;
		static bool mtSet;
	public:
		ttt();
		ttt(const vector<vector<char>> &b);
		ttt(const string &player1, const string &player2);
		~ttt();

		bool operator==(const ttt<DEBUG> &o) const;
		
		int move(int m);
		int moveRandom();
		int gameWon() const;
		
		void setBoard(const vector<vector<char>> &b);
		vector<vector<char>> getBoard();
		
	friend class hash_ttt<DEBUG>;
	friend ostream& operator<< <DEBUG>(ostream& s, const ttt<DEBUG> &t);
	
};

template<int DEBUG>
bool ttt<DEBUG>::mtSet = false;

template<int DEBUG>
mt19937 ttt<DEBUG>::mt;

template<int DEBUG>
ttt<DEBUG>::ttt()
{
	if(DEBUG) { cout << "ttt<DEBUG>::ttt();\n"; }
	if(DEBUG) { cout << "ttt<DEBUG>::ttt(): setup board\n"; }
	board.resize(3);
	for(auto &i: board)
	{
		i.resize(3);
		for(auto &j: i) { j = ' '; }
	}
	// history.push_back(board);
	if(DEBUG) { cout << "ttt<DEBUG>::ttt(): setup players\n"; }
	player.resize(2);
	player[0] = "";
	player[1] = "";
	if(DEBUG) { cout << "ttt<DEBUG>:ttt(): seed random number generator\n"; }
	if(mtSet == false)
	{
		mt.seed(chrono::system_clock::now().time_since_epoch().count());
		mtSet = true;
	}
	if(DEBUG) { cout << "end" << "ttt<DEBUG>::ttt();\n"; }
	return;
}

template<int DEBUG>
ttt<DEBUG>::ttt(const vector<vector<char>> &b)
	: ttt()
{
	board = b;
	return;
}

template<int DEBUG>
ttt<DEBUG>::ttt(const string &player1, const string &player2)
	: ttt()
{
	if(DEBUG) { cout << "ttt<DEBUG>::ttt(const string&, const string&);\n"; }

	player.resize(2);
	player[0] = player1; player[1] = player2;
	return;
}

template<int DEBUG>
ttt<DEBUG>::~ttt()
{
	if(DEBUG) { cout << "ttt<DEBUG>::~ttt();\n"; }
	return;
}

template<int DEBUG>
int ttt<DEBUG>::move(int m)
{
	int column, row;
	if(DEBUG) { cout << "ttt<DEBUG>::move(int);\n"; }
	switch(m) {
		case 1:
			column = 0; row = 2;
			break;
		case 2:
			column = 1; row = 2;
			break;
		case 3:
			column = 2; row = 2;
			break;
		case 4:
			column = 0; row = 1;
			break;
		case 5:
			column = 1; row = 1;
			break;
		case 6:
			column = 2; row = 1;
			break;
		case 7:
			column = 0; row = 0;
			break;
		case 8:
			column = 1; row = 0;
			break;
		case 9:
			column = 2; row = 0;
			break;
		default:
			return(-2);
	}
	if(board[column][row] != ' ') { return(-1); }
	board[column][row] = (turn++ % 2 == 0 ? 'X' : 'O');
//	history.push_back(board);
	return(0);
}

template<int DEBUG>
int ttt<DEBUG>::moveRandom()
{
	int	i, j, play, row, col;
	uniform_int_distribution<int> randomPlay(0, 8);

	if(DEBUG) { cout << "ttt<DEBUG>::moveRandom();\n"; }
	if(gameWon() > 0) return(-1);
	while(true) {
		play = randomPlay(mt);
		row = play % 3;
		col = play / 3;
		if(board[col][row] == ' ') break;
	}
	board[col][row] = (turn++ % 2 == 0 ? 'X' : 'O');
//	history.push_back(board);
	return(0);
}

template<int DEBUG>
void ttt<DEBUG>::setBoard(const vector<vector<char>> &b)
{
	board = b;
	return;
}



template<int DEBUG>
int ttt<DEBUG>::gameWon() const
{
	if(DEBUG) { cout << "ttt<DEBUG>::gameWon();\n"; }
	if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ') return( board[0][0] == 'X' ? 1 : 2);
	if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ') return( board[0][1] == 'X' ? 1 : 2);
	if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ') return( board[0][2] == 'X' ? 1 : 2);
	
	if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ') return( board[0][0] == 'X' ? 1 : 2);
	if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ') return( board[1][0] == 'X' ? 1 : 2);
	if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ') return( board[2][0] == 'X' ? 1 : 2);
	
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return( board[0][0] == 'X' ? 1 : 2);
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') return( board[2][0] == 'X' ? 1 : 2);
	for(auto i = 0; i < 3; i++)
		{
		for(auto j = 0; j < 3; j++)
		{
			if(board[i][j] == ' ') goto noWinner;
		}
	}
	if(DEBUG) { cout << "ttt<DEBUG>::gameWon() == 0\n"; }
	return(3);
noWinner:
	if(DEBUG) { cout << "ttt<DEBUG>::gameWon() == 0\n"; }
	return(0);

}

template<int DEBUG>
vector<vector<char>> ttt<DEBUG>::getBoard()
{
	return(board);
}

template<int DEBUG>
ostream& operator<<(ostream& s, const ttt<DEBUG> &t)
{
	if(DEBUG) { cout << "operator<<(ostream&, ttt<DEBUG> &);\n"; }
	s << "X : " << t.player[0] << "\n";
	s << "O : " << t.player[1] << "\n";
	s << t.board[0][0] << "|" << t.board[1][0] << "|" << t.board[2][0] << "\n";
	s << "-+-+-\n";
	s << t.board[0][1] << "|" << t.board[1][1] << "|" << t.board[2][1] << "\n";
	s << "-+-+-\n";
	s << t.board[0][2] << "|" << t.board[1][2] << "|" << t.board[2][2] << "\n";
	return s;
}

template<int DEBUG>
bool ttt<DEBUG>::operator==(const ttt<DEBUG> &o) const
{
	return board == o.board;
}


template<int DEBUG>
class hash_ttt {
public:
	size_t operator()(const ttt<DEBUG> &t) const {
		size_t	r = 0;
		for(auto i : t.board ) {
			for(auto j : i) {
				r^= hash<char>()(j);
			}
		}
		return r;
	}

};

#endif
