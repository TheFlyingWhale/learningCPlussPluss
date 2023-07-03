#include "utilities/utilities.h"
#include "./constants.h"

int main()
{
	bool willMainTerminate = false;
	while (!willMainTerminate)
	{
		willMainTerminate = commandHandler(ProcessConstants::MAIN);
	}
	return 0;
}