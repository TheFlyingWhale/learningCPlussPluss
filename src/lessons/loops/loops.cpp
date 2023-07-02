#include <iostream>
#include <string>
#include <vector>
#include <sstream>
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
	}

	return 0;
}

void printLoopLesson()
{
	system("clear");
	print("Loops");
	print("Are blocks of code thats beeing repeated");
	print("until a condition is met");
}

void requestLoopInput()
{
	newLine();
	print("Available commands:");

	string availableCommands[] = {
		"q - Exit lesson",
		"for [loops] - Runs a for loop that prints its index based on provided input",
	};

	for (string command : availableCommands)
	{
		cout << "\t" << command << endl;
	}
	print("");
}

void printForLoop(string inputString)
{
	char delimiter = ' ';
	vector<string> result;
	string::size_type start = 0;
	string::size_type end = inputString.find(delimiter);

	while (end != string::npos)
	{
		result.push_back(inputString.substr(start, end - start));
		start = end + 1;
		end = inputString.find(delimiter, start);
	}

	result.push_back(inputString.substr(start));

	int vectorSize = 0;
	vectorSize = int(result.size());

	if (vectorSize != 2)
	{
		print("Invalid input, try again\n");
		return;
	}

	int numberOfIterations = 0;
	try
	{
		numberOfIterations = stoi(result[1]);
	}
	catch (const invalid_argument &e)
	{
		print("Invalid input, try again\n");
		return;
	}

	printf("Number of iterations: %i\n", numberOfIterations);

	for (int i = 0; i < numberOfIterations; i++)
	{
		printf("Iteration %i\n", i + 1);
	}
}