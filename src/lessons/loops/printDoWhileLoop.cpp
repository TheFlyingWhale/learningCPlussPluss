#include "loops.h"
#include "../../utilities/utilities.h"
using namespace std;

void printDoWhileLoop()
{
	bool willDoWhileLoopTerminate = false;
	int iterations = 0;
	do
	{
		system("clear");
		printf("This is a Do While loop that will run indefinitely until a condition is met\n\n");
		printf("We are currently on iteration: %i\n\n", iterations);
		string input = requestInput("To meet the condition and break the loop write 'q'\nOr write whatever to do another iteration:");

		if (input == "q")
		{
			willDoWhileLoopTerminate = true;
			system("clear");
		}

		iterations++;
	} while (!willDoWhileLoopTerminate);
}