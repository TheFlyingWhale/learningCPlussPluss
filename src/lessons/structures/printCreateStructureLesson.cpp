#include <string>
#include "structures.h"
#include "../../utilities/utilities.h"
using namespace std;

void printCreateLesson()
{
	printf("In this lesson we're going to create people using a BasicPerson structure.\n");
	printf("When a person is created they'll be added to a vector.\n");
	printf("\n");
	printf("So the structure enables me to tell the vector what data it will be storing.\n");
	printf("When I list all the created people I can use a for each loop, and access the objects variables.\n");
	printf("I can also create a function that returns said structure!! Absolutely amazing!\n\n");

	vector<PersonStructure> people;

	bool amDoneWithCreating = false;
	do
	{
		string command = requestInput("q - Exit\nc - Create new person\np - Print the people you've created", true);
		if (command == "q")
		{
			amDoneWithCreating = true;
		}

		if (command == "c")
		{
			PersonStructure person = createPerson();
			people.push_back(person);
		}

		if (command == "p")
		{
			for (PersonStructure person : people)
			{
				printf("Name: %s\n", person.name.c_str());
				printf("Age: %i\n", person.age);
				printf("\n");
			}
		}

	} while (!amDoneWithCreating);
}

PersonStructure createPerson()
{
	PersonStructure newPerson;
	newPerson.name = requestInput("Please provide a name:", true);
	bool isAgeValid = false;
	while (!isAgeValid)
	{
		string providedAge = requestInput("Please provide an age:", true);
		try
		{
			newPerson.age = stoi(providedAge);
			isAgeValid = true;
		}
		catch (const invalid_argument &e)
		{
			printf("That was not valid input, please try again\n");
		}
	}

	return newPerson;
}