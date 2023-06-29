#include <iostream>
using namespace std;

int printProvidedInput(string input)
{
	cout << "You wrote: " << input.erase(0, 2) << endl;
	return 0;
}