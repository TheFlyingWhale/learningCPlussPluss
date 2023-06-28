#include <iostream>
#include "terminator.h"
using namespace std;

const char terminateChar = 'q';

int terminateProgram()
{
	system("clear");
	cout << "Program terminated" << endl;
	return 1;
}