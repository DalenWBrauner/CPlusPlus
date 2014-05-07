/*
Often I find myself wishing that built-in functions, classes, etc. just had ONE more feature.
This library is designed to provide just that; functions with slight modifications.
These functions are maybe also a little bit too nice.

Nice to meet you! My name is Dalen W. Brauner, and I hope you find these useful!
*/

#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

template<typename WhateverYouPlease>
void assertNicely(bool assertion, WhateverYouPlease message) {
	/* Trades assert()'s specification of line# for a too nice, programmer-specified error message! */
	if (!assertion) {
		cout << "\nPlease excuse me, but I must inform you: ";
		cout << message << endl;
		assert(false);
	}
}

bool askBoolNicely(string Question)
/* Pesters the user until they respond with 1 or 0. */
{
	string response = "One of infinitely many wrong answers";
	cout << Question;
	getline( cin, response );
	while ((response != "0") && (response != "1"))
	{
		response = "Still a wrong answer";
		cout << "Terribly sorry, but I need you to respond with either 1 or 0. ";
		getline( cin, response );
	}
	if		(response == "0") { return 0; }
	else if	(response == "1") { return 1; }
	else
	{
		cout << "I.. I have no idea how this happened... I'm so sorry.\nThe user said:\n";
		cout << response;
		cout << "\n(I hope that helped.)";
	}
	return 0;
}
