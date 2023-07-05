#include <iostream>
#include "commandHandler.h"
#include "../getCPlusPlusVersionAsString/getCPlusPlusVersionAsString.h"
using namespace std;

int displayCommands(bool invalidInput, ProcessConstants::ProcessName process)
{
	if (invalidInput)
	{
		displayInvalidCommand();
	}

	displayDefaultCommands();
	if (process == ProcessConstants::MAIN)
		displayMainCommands();

	if (process == ProcessConstants::LESSONS)
		displayLessonCommands();

	cout << endl;

	return 0;
}

void displayCommandsTitle(string title)
{
	cout << title << " commands:" << endl;
}

// <---- Invalid warning
void displayInvalidCommand()
{
	cout << "You provided an invalid command\n";
	cout << "Available commands is listed bellow \n\n";
}

// <---- Default commands
string defaultCommands[] = {
	"h - Help",
	"q - Exit",
};

void displayDefaultCommands()
{
	cout << "Compiled as " << getCPlusPlusVersionAsString() << "\n\n";

	displayCommandsTitle("Default");
	for (int i = 0; i < sizeof(defaultCommands) / sizeof(defaultCommands[0]); i++)
	{
		cout << "\t" << defaultCommands[i] << "\n";
	}
}

string mainCommands[] = {
	"l - Enter lessons"};

void displayMainCommands()
{
	displayCommandsTitle("Main");

	for (int i = 0; i < sizeof(mainCommands) / sizeof(mainCommands[0]); i++)
	{
		cout << "\t" << mainCommands[i] << "\n";
	}
}

// <---- Lesson commands
string lessonCommands[] = {
	"01 - Data Types",
	"02 - Operators",
	"03 - Switch",
	"04 - Loops",
	"05 - Structures"};

void displayLessonCommands()
{
	displayCommandsTitle("Lessons");
	for (int i = 0; i < sizeof(lessonCommands) / sizeof(lessonCommands[0]); i++)
	{
		cout << "\t" << lessonCommands[i] << "\n";
	}
	cout << endl;
}