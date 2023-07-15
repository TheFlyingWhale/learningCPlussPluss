#include <iostream>
#include <string>
#include "../print/print.h"
#include "requestInput.h"
using namespace std;
using namespace Print;

string requestInput(string prompt, bool clearAfterPrompt)
{
	string input = "";
	if (!prompt.empty())
	{
		print(prompt);
	}
	getline(cin, input);
	if (clearAfterPrompt)
	{
		clearTerminal();
	}
	return input;
}

string requestInput(void (*func)(), bool clearAfterPrompt)
{
	func();
	string input = "";
	getline(cin, input);
	if (clearAfterPrompt)
	{
		clearTerminal();
	}
	return input;
}

void clearTerminal()
{
	printf("\033[2J\033c");
}