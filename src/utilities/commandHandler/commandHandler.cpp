#include <iostream>
#include <string>
#include <array>
#include "commandHandler.h"
#include "../../lessons/lessons.h"
#include "../printProvidedInput/printProvidedInput.h"

using namespace std;
string providedInput = "";

int commandHandler(ProcessConstants::ProcessType process)
{
	providedInput = requestCommand(process);
	const char commandChar = providedInput[0];

	if (commandChar == 'q')
		return terminateProgram(process);

	if (commandChar == 'h')
		return displayCommands(false, process);

	if (process == ProcessConstants::LESSONS)
		return lessonCommandHandler(providedInput);

	if (commandChar == 'l')
		return lessonHandler();

	return displayCommands(true, "");

	return 0;
}

string requestCommand(ProcessConstants::ProcessType process)
{
	cout << process << " - (h for help):" << endl;
	getline(cin, providedInput);
	system("clear");
	return providedInput;
}

int lessonCommandHandler(string input)
{
	if (input.size() != 2)
	{
		displayCommands(true, ProcessConstants::LESSONS);
		return 0;
	}

	if (input == "01")
	{
		cout << "You selected 01 lesson" << endl;
		return 0;
	}

	return displayCommands(true, ProcessConstants::LESSONS);

	return 0;
}
