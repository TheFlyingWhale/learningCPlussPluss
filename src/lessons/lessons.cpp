#include "../utilities/utilities.h"
#include <iostream>
using namespace std;

bool willLessonTerminate = false;

int lessonHandler()
{
	while (!willLessonTerminate)
	{
		willLessonTerminate = commandHandler(ProcessConstants::LESSONS);
	}
	return 0;
}