#include <iostream>
#include <string>
#include "pointers.h"
using namespace std;

void printFunctionWithPointerLesson()
{
	printf("This lesson passes pointers as parameters to functions\n");
	string weather = "Rain";
	printf("There is a string variable with the value of 'Rain'\n");
	int temperature = 17;
	printf("And there is a integer variable with the value of '17'\n");

	printf("\n");
	printf("After showing you the variables you'll be able to change them\n");
	printf("using functions that takes the pointer as a parameter\n");

	funcWithStrPoiPar(&weather);
	funcWithIntPoiPar(&temperature);

	editStringPointerValue(&weather);
	editIntPointerValue(&temperature);

	funcWithStrPoiPar(&weather);
	funcWithIntPoiPar(&temperature);
}

void funcWithStrPoiPar(string *strPoi)
{
	printf("\n");
	printf("This is a function that takes a string pointer as a parameter\n");
	printf("Memory address: %p\n", strPoi);
	printf("Value of address: %s\n", strPoi->c_str());
}

void funcWithIntPoiPar(int *intPoi)
{
	printf("\n");
	printf("This is a function that takes a int pointer as a parameter\n");
	printf("Memory address: %p\n", intPoi);
	printf("Value of address: %i\n", *intPoi);
}

void editStringPointerValue(string *strPtr)
{
	printf("\n");
	printf("Please provide some input to change the string variable\n");
	getline(cin, *strPtr);
}

void editIntPointerValue(int *intPtr)
{
	printf("\n");
	string input;
	bool validInput = false;
	printf("Please provide some input to change the int variable\n");
	while (!validInput)
	{
		getline(cin, input);
		try
		{
			*intPtr = stoi(input);
			validInput = true;
		}
		catch (const invalid_argument &e)
		{
			printf("That was not a valid input, please try again");
		}
	}
}