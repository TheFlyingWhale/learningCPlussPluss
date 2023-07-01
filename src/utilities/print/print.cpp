#include <iostream>
using namespace std;

// Passes a std::endl to std::out
void newLine()
{
	cout << endl;
}

// Passes a description followed by the result to std::out
void printMath(string description, int result)
{
	cout << description << " = " << result << endl;
}