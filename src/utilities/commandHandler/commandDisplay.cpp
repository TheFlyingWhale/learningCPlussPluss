#include "commandHandler.h"
#include <iostream>
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
array<string, 3> defaultCommands = {
	"h - Help",
	"q - Exit",
};

void displayDefaultCommands()
{
	displayCommandsTitle("Default");
	for (int i = 0; i < defaultCommands.size(); i++)
	{
		cout << "\t" << defaultCommands[i] << "\n";
	}
}

array<string, 1> mainCommands = {
	"l - Enter lessons"};

void displayMainCommands()
{
	displayCommandsTitle("Main");

	for (int i = 0; i < mainCommands.size(); i++)
	{
		cout << "\t" << mainCommands[i] << "\n";
	}
}

// <---- Lesson commands
array<string, 2> lessonCommands = {
	"01 - Data Types",
	"02 - Operators"};

void displayLessonCommands()
{
	displayCommandsTitle("Lessons");
	for (int i = 0; i < lessonCommands.size(); i++)
	{
		cout << "\t" << lessonCommands[i] << "\n";
	}
	cout << endl;
}