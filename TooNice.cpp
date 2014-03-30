/*
Often I find myself wishing that built-in functions, classes, etc. just had ONE more feature.
This library is designed to provide just that; functions with slight modifications.
These functions are maybe also a little bit too nice.

Nice to meet you! My name is Dalen W. Brauner, and I hope you find these useful!
*/

#include <assert.h>
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
};
