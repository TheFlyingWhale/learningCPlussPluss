#include <iostream>
#include "../lessons.h"
#include "../../utilities/utilities.h"
#include "dataTypes.h"
using namespace std;

// This is a number
int myNumber = 5;

// This is a float
// Consumes 4 bytes of memory
// Is less precise
float myFloat = 5.99;

// This is a double
// Consumes 8 bytes of memory
// Is more precise
double myDouble = 9.89;

/*
What does it mean that a double is more precise than a float?
	It means the different amount of digits following the decimal point.
	A float can only have six or seven decimal digits
	While a double can hold up to about 15

	For that reason its safer to use double when doing calculations
	using numbers with decimals
*/

/*
Scientific Numbers
	A floating point number can also be a scientific number
	using an "e" to indicate the power of 10
*/

float myFloatWithPower = 34e3;

double myDoubleWithPower = 12E4;

// This is a character
// Wrapped by Apostrophes -> ''
char myChar = 'D';

// You can also use ASCII values to display a certain character
char myAsciiChar = 68;

// This is a string
// Wrapped by Ditto marks -> ""
// Is just an array of chars
string myString = "My string";

// This is a boolean
// Boolean takes the values "true" or "false"
// But under the hud its just 1 or 0
bool myBool = false;

template <typename T>
void printExample(T value, const string additionalText)
{
	if (!additionalText.empty())
	{
		cout << value << " is a " << getTypeAsString<decltype(value)>() << " " << additionalText << endl;
		return;
	}
	cout << value << " is a " << getTypeAsString<decltype(value)>() << endl;
}

void printAllDataTypeExamples()
{
	printExample(myNumber);

	printExample(myFloat);
	printExample(myFloatWithPower, "which uses 'e' to power the number");

	printExample(myDouble);
	printExample(myDoubleWithPower, "which uses 'e' to power the number");

	printExample(myChar);
	printExample(myAsciiChar, "which uses the '68' ASCII value");

	printExample(myString);
	printExample(myBool);
}