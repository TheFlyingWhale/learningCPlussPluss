#include <iostream>
#include <string>
#include "utilities/utilities.h"
using namespace std;

bool willMainTerminate = false;

int main()
{
	system("clear");
	cout << "Welcome to the learning file" << endl;
	while (!willMainTerminate)
	{
		willMainTerminate = inputHandler();
	}
	return 0;
}