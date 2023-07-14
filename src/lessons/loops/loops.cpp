#include <iostream>
#include <string>
#include "../../utilities/utilities.h"
#include "loops.h"
using namespace std;

void loopLessonHandler()
{
	printLoopLesson();
	int willLoopLessonTerminate = false;
	while (!willLoopLessonTerminate)
	{
		willLoopLessonTerminate = loopLesson();
	}
}

int loopLesson()
{
	string input = requestInput(requestLoopInput, true);

	if (input == "q")
		return 1;

	if (input.substr(0, 3) == "for")
	{
		printForLoop(input);
		return 0;
	}

	if (input == "while")
	{
		printDoWhileLoop();
		return 0;
	}

	printf("No valid command was provided\n");

	return 0;
}

void printLoopLesson()
{
	system("clear");
	printf("Loops\n");
	printf("Are blocks of code thats beeing repeated until a condition is met\n");
}

void requestLoopInput()
{
	printf("\n");
	printf("Available commands:\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"for [number] - Runs a For Loop based on provided number",
		"\t-b [number] - Breaks the loop on provided number",
		"\t-c [number] - Continues the loop on provided number",
		"while - Run a Do While loop"};

	for (string command : availableCommands)
	{
		cout << "\t" << command << endl;
	}
	printf("\n");
}