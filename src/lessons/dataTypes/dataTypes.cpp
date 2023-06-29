#include <iostream>
#include <type_traits>
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

// This is a character
// Wrapped by Apostrophes -> ''
char myChar = 'D';

// This is a string
// Wrapped by Ditto marks -> ""
// Is just an array of chars
string myString = "My string";

// This is a boolean
bool myBool = false;

template <typename T>
string getTypeName()
{
	if (is_same<T, int>::value)
		return "int";

	if (is_same<T, float>::value)
		return "float";

	if (is_same<T, double>::value)
		return "double";

	if (is_same<T, char>::value)
		return "char";

	if (is_same<T, string>::value)
		return "string";

	if (is_same<T, bool>::value)
		return "boolean";

	return "unknown";
}

template <typename T>
void printExample(T value)
{
	cout << "This is value: " << value << " which is of type " << getTypeName<decltype(value)>() << endl;
}

void printAllDataTypeExamples()
{
	printExample(myNumber);
	printExample(myFloat);
	printExample(myDouble);
	printExample(myChar);
	printExample(myString);
	printExample(myBool);
}