#include "references.h"
#include <string>
#include "../../utilities/utilities.h"
using namespace std;

void referencesLessonHandler()
{
	printReferencesLesson();
	int willTerminate = false;
	while (!willTerminate)
	{
		willTerminate = referencesLesson();
	}
}

void printReferencesLesson()
{
	system("clear");
	printf("References\n");
	printf("Are variables that references existing variables.\n");
	printf("They can be used to provide a references to some data rather than the data itself.\n");
	printf("Lets say some data is quite large, then its more efficient to send a reference to that data.\n");
	printf("This also enables us to manipulate or replace that that data in other places in the application\n");
	printf("\n");
	printf("To create a reference we use the '&' symbol\n");
	printf("Not only can it be used to create references, it can also be used to get the memory address of a variable\n");
	printf("\n");
	printf("Creating a reference:\n");
	printf("string &variableName = variableToReference\n");
	printf("\n");
	printf("Getting a memory address:\n");
	printf("cout << &variableName;\n");
}

int referencesLesson()
{
	string input = requestInput(requestReferencesInput, true);

	if (input == "q")
	{
		return 1;
	}

	if (input == "u")
	{
		printReferencesExample();
		return 0;
	}

	if (input == "m")
	{
		printGettingMemoryAddressExample();
		return 0;
	}

	return 0;
}

void requestReferencesInput()
{
	printf("\n");
	printf("Available commands\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"u - Using references",
		"m - Getting memory address"};

	for (string command : availableCommands)
	{
		printf("\t%s\n", command.c_str());
	}
}

void printReferencesExample()
{
	string myName = "Ole";
	printf("In this exercise I'll be using a string, with a variable name 'myName' which holds the string 'Ole'\n");
	printf("Here is a direct print of the variable 'myName' variable: %s\n", myName.c_str());
	printf("\n");
	string &refOne = myName;
	printf("Now I've created a variable 'refOne', which is a reference to the 'myName' variable\n");
	printf("Here is a print of the 'refOne' reference rather than the 'myName' variable: %s\n", refOne.c_str());
	printf("\n");
	string &refTwo = refOne;
	printf("Now I've created another variable 'refTwo', which is a reference to the 'refOne' reference\n");
	printf("Here is a print of the 'refTwo' reference: %s\n", refTwo.c_str());
}

void printGettingMemoryAddressExample()
{
	string myName = "Ole";
	printf("In this exercise I'll be using a string, with a variable name 'myName' which holds the string 'Ole'\n");
	printf("Here I'm printing the value of 'myName': %s\n", myName.c_str());
	printf("\n");
	printf("Here I'm printing the memory address to 'myName' using '&myName': %p\n", &myName);
}