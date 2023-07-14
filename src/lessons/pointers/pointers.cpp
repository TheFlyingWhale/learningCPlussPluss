#include <string>
#include "../../utilities/utilities.h"
#include "pointers.h"
using namespace std;

void pointersLessonHandler()
{
	printPointersLesson();
	int willTerminate = false;
	while (!willTerminate)
	{
		willTerminate = pointersLesson();
	}
}

void printPointersLesson()
{
	printf("This is the pointers lesson\n");
}

int pointersLesson()
{
	system("clear");
	string input = requestInput(requestPointersInput, true);

	if (input == "q")
	{
		return 1;
	}

	if (input == "b")
	{
		printBasicPointersLesson();
		return 0;
	}

	if (input == "p")
	{
		printPracticePointerLesson();
		return 0;
	}

	if (input == "f")
	{
		printFunctionWithPointerLesson();
		return 0;
	}

	return 0;
}

void requestPointersInput()
{
	printf("\n");
	printf("Please provide some input\n");

	printf("Available commands:\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"b - Basic lesson",
		"p - Practice pointers even more",
		"f - Pointers as function parameters"};

	for (string command : availableCommands)
	{
		printf("\t%s\n", command.c_str());
	}
}
