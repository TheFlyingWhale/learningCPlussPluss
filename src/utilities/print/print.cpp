#include <iostream>
#include <string>
#include "print.h"
using namespace std;

namespace Print
{
	void newline()
	{
		cout << endl;
	}

	void math(string description, int result)
	{
		cout << description << " = " << result << endl;
	}

	void error(string message)
	{
		cout << rich("Error: ", Color::red, Decoration::bold) << message << endl;
	};

	void success(string message)
	{
		cout << rich("Success: ", Color::green, Decoration::bold) << message << endl;
	}

	// Only color
	string rich(string text, Color color)
	{
		return "\033[" + to_string(color) + "m" + text + "\033[0m";
	}

	// Only decoration
	string rich(string text, Decoration decoration)
	{
		return "\033[" + to_string(decoration) + "m" + text + "\033[0m";
	}

	// Color and decoration
	string rich(string text, Color color, Decoration decoration)
	{
		return "\033[" + to_string(decoration) + ";" + to_string(color) + "m" + text + "\033[0m";
	}
};