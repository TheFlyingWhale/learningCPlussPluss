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
		cerr << "\033[1;31mError:\033[0m " << message << endl;
	};

	void success(string message)
	{
		cerr << "\033[1;32mSuccess:\033[0m " << message << endl;
	}
};