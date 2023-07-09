#include <string>
#include "structures.h"
using namespace std;

struct
{
	string name;
	int age;
} person1, person2, person3;

void printBasicLesson()
{
	person1.name = "Ole";
	person1.age = 27;

	person2.name = "Eric";
	person2.age = 27;

	person3.name = "Nicolas";
	person3.age = 22;

	printf("In this lesson I've created a structure that holds name and age, representing a person.\n\n");
	printf("BasicPerson 1:\n");
	printf("\tName:%s\n", person1.name.c_str());
	printf("\tAge:%i\n\n", person1.age);
	printf("BasicPerson 2:\n");
	printf("\tName:%s\n", person2.name.c_str());
	printf("\tAge:%i\n\n", person2.age);
	printf("BasicPerson 3:\n");
	printf("\tName:%s\n", person3.name.c_str());
	printf("\tAge:%i\n\n", person3.age);
	printf("The boring part here is that I had to create the used variable right after the structure.\n");
	printf("Basically making the structure only usable one place in the code.\n");
	printf("And basically can't be placed in an array, which needs to know what type of data it holds.\n");
}