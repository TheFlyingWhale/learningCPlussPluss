#include <iostream>
#include <string>
#include "utilities/utilities.h"
#include "./constants.h"
using namespace std;

bool willMainTerminate = false;

int main()
{
	while (!willMainTerminate)
	{
		willMainTerminate = commandHandler(ProcessConstants::MAIN);
	}
	return 0;
}