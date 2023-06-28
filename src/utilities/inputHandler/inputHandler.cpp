#include <iostream>
#include <string>
#include "inputHandler.h"

using namespace std;
string providedInput = "";

int inputHandler()
{
	providedInput = requestInput();
	const char commandChar = providedInput[0];

	if (commandChar == 'q')
		return terminateProgram();

	if (commandChar == 'h')
		return displayCommands();

	if (commandChar == 'p')
		return printProvidedInput(providedInput);

	return 0;
}

string requestInput()
{
	cout << "\nPlease provide input (h for help):";
	getline(cin, providedInput);
	system("clear");
	return providedInput;
}

int displayCommands()
{
	cout << "Command list:\n";
	cout << "\th - Help\n";
	cout << "\tq - Terminate program\n";
	cout << "\tp [string] - Prints provided string\n";

	return 0;
}

int printProvidedInput(string input)
{
	cout << "You wrote: " << input.erase(0, 2) << endl;
	return 0;
}