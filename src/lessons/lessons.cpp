#include "../utilities/utilities.h"
#include <iostream>
using namespace std;

bool willLessonTerminate = false;

int lessonHandler()
{
	willLessonTerminate = false;
	while (!willLessonTerminate)
	{
		willLessonTerminate = commandHandler(ProcessConstants::LESSONS);
	}
	return 0;
}