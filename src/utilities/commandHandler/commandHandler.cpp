#include <iostream>
#include <string>
#include <array>
#include "commandHandler.h"
#include "../../lessons/lessons.h"

using namespace std;
string providedInput = "";

int commandHandler(ProcessConstants::ProcessName process)
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

string requestCommand(ProcessConstants::ProcessName process)
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
		printDataTypesLesson();
		return 0;
	}

	if (input == "02")
	{
		printOperatorsLesson();
		return 0;
	}

	if (input == "03")
	{
		switchLessonHandler();
		return 0;
	}

	if (input == "04")
	{
		loopLessonHandler();
		return 0;
	}

	if (input == "05")
	{
		structuresLessonHandler();
		return 0;
	}

	if (input == "06")
	{
		referencesLessonHandler();
	}

	return displayCommands(true, ProcessConstants::LESSONS);

	return 0;
}
