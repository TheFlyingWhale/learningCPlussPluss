#include <string>
#include "../../utilities/utilities.h"
#include "pointers.h"

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
		"p - Practice pointers even more"};

	for (string command : availableCommands)
	{
		printf("\t%s\n", command.c_str());
	}
}

void printBasicPointersLesson()
{
	string myName = "Ole";
	printf("In this exercise I'll be using a string, with a variable name 'myName' which holds the string 'Ole'\n");
	printf("Here is a direct print of the variable 'myName' variable: %s\n", myName.c_str());
	printf("\n");
	string *pointerOne = &myName;
	printf("Now I've created a variable 'pointerOne', which is a pointer to the memory address of 'myName'\n");
	printf("Here is a print of the 'pointerOne' variable: %p\n", pointerOne);
	printf("\n");
	printf("In the following example I'll be printing the contents of the memory address rather than the 'pointerOne' variable itself\n");
	printf("This is whats to be found in the memory address: %s\n", pointerOne->c_str());
	printf("\n");
	*pointerOne = "Pål";
	printf("Now I've changed the contents of 'myName', but I've done so trough 'pointerOne'\n");
	printf("This is a print of the same address, no changes here: %p\n", pointerOne);
	printf("Here is a print of the 'myName' variable: %s\n", myName.c_str());
	printf("And where it a print of whats to be found on the memory address: %s\n", pointerOne->c_str());
}

void printPracticePointerLesson()
{
	int age = 26;
	string name = "Knut";
	int *agePointer = &age;
	string *namePointer = &name;
	printf("age: %i\n", age);
	printf("name: %s\n", name.c_str());
	printf("agePointer: %p\n", agePointer);
	printf("namePointer: %p\n", namePointer);
	printf("dereferenced agePointer: %i\n", *agePointer);
	printf("dereferenced namePointer: %s\n", namePointer->c_str());
	printf("\n");
	*agePointer = 30;
	*namePointer = "Pål";
	printf("Here I've changed the ageVariable trough *agePointer and the nameVariable trough *namePointer\n");
	printf("age: %i\n", age);
	printf("name: %s\n", name.c_str());
	printf("agePointer: %p\n", agePointer);
	printf("namePointer: %p\n", namePointer);
	printf("dereferenced age: %i\n", *agePointer);
	printf("dereferenced name: %s\n", namePointer->c_str());
	printf("\n");
	*agePointer = 20;
	*namePointer = "Nils";
	printf("Here I've done the same changes for even more practice\n");
	printf("age: %i\n", age);
	printf("name: %s\n", name.c_str());
	printf("agePointer: %p\n", agePointer);
	printf("namePointer: %p\n", namePointer);
	printf("dereferenced age: %i\n", *agePointer);
	printf("dereferenced name: %s\n", namePointer->c_str());
}