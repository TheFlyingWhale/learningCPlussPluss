#include <iostream>
#include <string>
#include <vector>
#include "structures.h"
#include "../../utilities/utilities.h"
using namespace std;

void structuresLessonHandler()
{
	printStructureLesson();
	int willTerminate = false;
	while (!willTerminate)
	{
		willTerminate = structuresLesson();
	}
}

int structuresLesson()
{
	string input = requestInput(requestStructureInput, true);

	if (input == "q")
	{
		return 1;
	}

	if (input == "basic")
	{
		printBasicLesson();
		return 0;
	}

	if (input == "named")
	{
		printNamedLesson();
		return 0;
	}

	if (input == "create")
	{
		printCreateLesson();
		return 0;
	}

	return 0;
}

void printStructureLesson()
{
	system("clear");
	printf("Structures\n");
	printf("Are a group of related variables, which can for example be used as a type\n");
}

void requestStructureInput()
{
	printf("\n");
	printf("Available commands:\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"basic - Runs the basic lesson",
		"named - Same as basic, but with named structures",
		"create - Creating people using named structures"};

	for (string command : availableCommands)
	{
		printf("\t%s\n", command.c_str());
	}
	printf("\n");
}