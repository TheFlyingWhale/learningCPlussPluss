#include <string>
#include "pointers.h"
using namespace std;

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