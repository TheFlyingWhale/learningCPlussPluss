#include <iostream>
#include "terminator.h"
using namespace std;

const char terminateChar = 'q';

int terminateProgram(ProcessConstants::ProcessType process)
{
	system("clear");
	cout << "You've exited " << process << endl;
	return 1;
}