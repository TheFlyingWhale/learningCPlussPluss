#include <iostream>
#include <string>
#include "utilities/utilities.h"
using namespace std;

bool willMainTerminate = false;

int main()
{
	system("clear");
	cout << "Welcome to the learning C++ project" << endl;
	while (!willMainTerminate)
	{
		willMainTerminate = inputHandler();
	}
	return 0;
}