#include <string>
#include "pointers.h"
using namespace std;

void printPracticePointerLesson()
{
	int age = 26;
	string name = "Knut";
	int *agePointer = &age;
	string *namePointer = &name;
	int &ageReference = age;
	printf("age: %i\n", age);
	printf("name: %s\n", name.c_str());
	printf("agePointer: %p\n", agePointer);
	printf("namePointer: %p\n", namePointer);
	printf("dereferenced agePointer: %i\n", *agePointer);
	printf("dereferenced namePointer: %s\n", namePointer->c_str());
	printf("\n");
	*agePointer = 30;
	*namePointer = "Pål";
	printf("Here I've changed the ageVariable trough *agePointer and the nameVariable trough *namePointer\n");
	printf("age: %i\n", age);
	printf("name: %s\n", name.c_str());
	printf("agePointer: %p\n", agePointer);
	printf("namePointer: %p\n", namePointer);
	printf("dereferenced age: %i\n", *agePointer);
	printf("dereferenced name: %s\n", namePointer->c_str());
	printf("\n");
	*agePointer = 20;
	*namePointer = "Nils";
	printf("Here I've done the same changes for even more practice\n");
	printf("age: %i\n", age);
	printf("name: %s\n", name.c_str());
	printf("agePointer: %p\n", agePointer);
	printf("namePointer: %p\n", namePointer);
	printf("dereferenced age: %i\n", *agePointer);
	printf("dereferenced name: %s\n", namePointer->c_str());
}