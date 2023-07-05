#include "structures.h"
#include <string>
using namespace std;

void printNamedLesson()
{
	vector<PersonStructure> myPeople;
	PersonStructure person1;
	person1.name = "Ole";
	person1.age = 27;
	myPeople.push_back(person1);

	PersonStructure person2;
	person2.name = "Eric";
	person2.age = 27;
	myPeople.push_back(person2);

	PersonStructure person3;
	person3.name = "Nicolas";
	person3.age = 22;
	myPeople.push_back(person3);

	printf("In this example I've created a named structure called PersonStructure.\n");
	printf("This enables me to easily use this structure to create variables wherever I want.\n");
	printf("And I can use them as a type for arrays or vectors.\n");

	for (PersonStructure person : myPeople)
	{
		printf("\n");
		printf("Name: %s\n", person.name.c_str());
		printf("Age: %i\n", person.age);
	}
}