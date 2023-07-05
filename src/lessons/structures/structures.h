#ifndef STRUCTURES_LESSON
#define STRUCTURES_LESSON
#include <string>

void structuresLessonHandler();

int structuresLesson();

void printStructureLesson();

void requestStructureInput();

void printBasicLesson();

void printNamedLesson();

void printCreateLesson();

struct PersonStructure
{
	std::string name;
	int age;
};

PersonStructure createPerson();

#endif