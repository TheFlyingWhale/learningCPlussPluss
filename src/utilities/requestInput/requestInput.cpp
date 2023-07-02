#include <iostream>
#include <string>
#include "../print/print.h"
#include "requestInput.h"
using namespace std;

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
		system("clear");
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
		system("clear");
	}
	return input;
}