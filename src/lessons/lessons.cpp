#include "../utilities/utilities.h"
#include <iostream>
using namespace std;

int lessonHandler()
{
	bool willLessonTerminate = false;
	while (!willLessonTerminate)
	{
		willLessonTerminate = commandHandler(ProcessConstants::LESSONS);
	}
	return 0;
}