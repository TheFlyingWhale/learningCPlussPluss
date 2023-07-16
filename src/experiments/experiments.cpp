#include "../utilities/utilities.h"
#include <iostream>
using namespace std;

int experimentsHandler()
{
	bool willExperimentsTerminate = false;
	while (!willExperimentsTerminate)
	{
		willExperimentsTerminate = commandHandler(ProcessConstants::EXPERIMENTS);
	}
	return 0;
}