#include <iostream>

/* For debugging purposes, the Trickster will cout whenever it is created */
class Trickster
{
	public:
		Trickster();
};

// THEY THINK THEY'RE SOOOOO CLEVER
Trickster::Trickster()
{
	std::cout << "<<~<< heh >>~>>\n";
}
