#include "utilities/utilities.h"
#include "./constants.h"

bool willMainTerminate = false;

int main()
{
	while (!willMainTerminate)
	{
		willMainTerminate = commandHandler(ProcessConstants::MAIN);
	}
	return 0;
}