#include <iostream>
#include "getTypeAsString.h"

using namespace std;

// Takes a value and return its type
template <typename T>
string getTypeAsString()
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

template string getTypeAsString<int>();
template string getTypeAsString<float>();
template string getTypeAsString<double>();
template string getTypeAsString<char>();
template string getTypeAsString<std::string>();
template string getTypeAsString<bool>();