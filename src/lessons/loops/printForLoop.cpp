#include <vector>
#include <sstream>
#include "loops.h"

using namespace std;

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

	int breakAt = 0;
	bool isBreakSet = false;
	int continueAt = 0;
	bool isContinueSet = false;
	int vectorSize = int(result.size());
	int numberOfIterations = 0;

	try
	{
		numberOfIterations = stoi(result[1]);
	}
	catch (const invalid_argument &e)
	{
		printf("Invalid input, for must be followed by a number\n");
		return;
	}

	if (numberOfIterations < 1)
	{
		printf("Invalid input, number of iterations must be a positive number");
		return;
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (result.at(i) == "-b")
		{
			try
			{
				breakAt = stoi(result.at(i + 1));
				isBreakSet = true;
			}
			catch (const invalid_argument &e)
			{
				printf("Invalid input, try again\n");
				return;
			}
		}

		if (result.at(i) == "-c")
		{
			try
			{
				continueAt = stoi(result.at(i + 1));
				isContinueSet = true;
			}
			catch (const invalid_argument &e)
			{
				printf("Invalid input, try again\n");
				return;
			}
		}
	}

	if (isBreakSet && isContinueSet && breakAt == continueAt)
	{
		printf("Invalid input, you can't break and continue at the same point\n");
		return;
	}

	if (isBreakSet && numberOfIterations <= breakAt)
	{
		printf("Invalid break point, number to large\n");
		return;
	}

	if (isBreakSet && breakAt < 1)
	{
		printf("Invalid break point, number to small\n");
		return;
	}

	if (isContinueSet && numberOfIterations <= continueAt)
	{
		printf("Invalid continue point, number to large\n");
		return;
	}

	if (isContinueSet && continueAt < 1)
	{
		printf("Invalid continue point, number to small\n");
		return;
	}

	for (int i = 0; i < numberOfIterations; i++)
	{
		if (isBreakSet && i == breakAt)
		{
			printf("Breaking the loop on iteration %i\n", i);
			break;
		}

		if (isContinueSet && i == continueAt)
		{
			printf("Skips iteration %i\n", i);
			continue;
		}

		printf("Iteration %i\n", i);
	}
}