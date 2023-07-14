#include <cstdlib>
#include "utilities/utilities.h"
#include "./constants.h"
using namespace std;

int main()
{
	clearTerminal();
	bool willMainTerminate = false;
	while (!willMainTerminate)
	{
		willMainTerminate = commandHandler(ProcessConstants::MAIN);
	}
	return 0;
}