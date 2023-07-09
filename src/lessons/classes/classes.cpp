#include "classes.h"
#include <unordered_map>
#include <string>
#include "../../utilities/utilities.h"
using namespace std;

void classesLessonHandler()
{
	printClassesLesson();
	int willTerminate = false;
	while (!willTerminate)
	{
		willTerminate = classesLesson();
	}
}

int classesLesson()
{
	string input = requestInput(requestClassesInput, true);

	if (input == "q")
	{
		return 1;
	}

	if (input == "b")
	{
		basicClassLesson();
		return 0;
	}

	if (input == "m")
	{
		classesWithMethodsLesson();
		return 0;
	}

	if (input == "c")
	{
		classesConstructorsLesson();
		return 0;
	}

	if (input == "a")
	{
		classesAccessLesson();
		return 0;
	}

	if (input == "e")
	{
		classesWithEncapsulationLesson();
		return 0;
	}

	return 0;
}

void printClassesLesson()
{
	printf("This is the classes lesson\n");
}

void requestClassesInput()
{
	printf("\n");
	printf("Available commands\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"b - Basic classes lesson",
		"m - Classes with methods",
		"c - Classes with constructors",
		"a - Classes with specific access",
		"e - Classes with encapsulation"};

	for (string command : availableCommands)
	{
		printf("\t%s\n", command.c_str());
	}
}

class BasicPerson
{
public:
	string name = "No name";
	int age = 0;
	string favoriteFood = "No favorite food";
};

void basicClassLesson()
{
	BasicPerson personOne;
	personOne.name = "Ole";
	personOne.age = 27;
	personOne.favoriteFood = "Pizza";

	BasicPerson personTwo;
	personTwo.name = "Eric";
	personTwo.age = 27;
	personTwo.favoriteFood = "Sushi";

	BasicPerson personThree;
	personThree.name = "Nicolas";
	personThree.age = 22;
	personThree.favoriteFood = "Yogurt";

	printf("In this lesson I've created a class called BasicPerson\n");
	printf("This class has three attributes; name, age and favorite food\n");
	printf("Ive created three people, and will be using a function(for this example) to print out their details\n");
	printPerson(personOne);
	printPerson(personTwo);
	printPerson(personThree);
}

void printPerson(BasicPerson person)
{
	printf("\n");
	printf("Name: %s\n", person.name.c_str());
	printf("Age: %i\n", person.age);
	printf("Favorite food: %s\n", person.favoriteFood.c_str());
}

class MethodPerson : public BasicPerson
{
public:
	void printVariables()
	{
		printf("\n");
		printf("Name: %s\n", name.c_str());
		printf("Age: %i\n", age);
		printf("Favorite food: %s\n", favoriteFood.c_str());
	}
	bool isNameTheSame(string compareName)
	{
		return name == compareName;
	}
};

void classesWithMethodsLesson()
{
	MethodPerson personOne;
	personOne.name = "Ole";
	personOne.age = 27;
	personOne.favoriteFood = "Pizza";

	MethodPerson personTwo;
	personTwo.name = "Eric";
	personTwo.age = 27;
	personTwo.favoriteFood = "Sushi";

	MethodPerson personThree;
	personThree.name = "Nicolas";
	personThree.age = 22;
	personThree.favoriteFood = "Yogurt";

	printf("In this lesson I've created a class called MethodPerson\n");
	printf("This class have the same three attributes, but with a method\n");
	printf("\n");
	printf("Said method simply prints its atributes\n");
	printf("replacing the need for an external function which does the same thing\n");
	printf("The class also have a method 'isNameTheSame' that lets you compare provided name with the objects name\n");
	printf("\n");
	printf("To throw in some extra spice I've also used Inheritance, but more on that later\n");

	personOne.printVariables();
	personTwo.printVariables();
	personThree.printVariables();

	printf("\n");
	printf("Is the name of personOne 'Ole'?: %i\n", personOne.isNameTheSame("Ole"));
	printf("Is the name of personOne 'Truls'?: %i\n", personTwo.isNameTheSame("Truls"));
}

struct ConstructorPersonParameters
{
	string name;
	int age;
	string favoriteFood;
};

class ConstructorPerson : public MethodPerson
{
public:
	ConstructorPerson(string pName = "No name", int pAge = 0, string pFavoriteFood = "Sand")
	{
		name = pName;
		age = pAge;
		favoriteFood = pFavoriteFood;
	}
	ConstructorPerson(const ConstructorPersonParameters &person = {})
	{
		if (!person.name.empty())
		{
			name = person.name;
		}
		if (person.age != 0)
		{
			age = person.age;
		}
		if (!person.favoriteFood.empty())
		{
			favoriteFood = person.favoriteFood;
		}
	}
};

void classesConstructorsLesson()
{
	ConstructorPerson personOne("Ole", 27, "Pizza");
	ConstructorPerson personTwo("Eric", 27, "Sushi");
	ConstructorPerson personThree("Nicolas", 22, "Yogurt");

	ConstructorPersonParameters perFour{"Pål", 20, "Beans"};
	ConstructorPerson personFour(perFour);
	ConstructorPersonParameters perFive{.name = "Knut", .age = 25};
	ConstructorPerson personFive(perFive);
	ConstructorPerson personSix({.name = "Bertil", .age = 30});

	printf("In this lesson I've created a class called ConstructorPerson\n");
	printf("This class have the same attributes and methods as MethodPerson\n");
	printf("\n");
	printf("The difference is that the class uses a constructor.\n");
	printf("The constructors lets me provide it with data upon initialisation\n");
	printf("rather than after the object is created\n");

	// personOne.printVariables();
	// personTwo.printVariables();
	// personThree.printVariables();

	personFive.printVariables();
	personSix.printVariables();
}

class AccessPerson : public ConstructorPerson
{
public:
	using ConstructorPerson::ConstructorPerson;

	void setSecret(string pSecret)
	{
		secret = pSecret;
	}

	string getSecret()
	{
		return secret;
	}

	void printSecret()
	{
		printf("Secret: %s\n", secret.c_str());
	}

private:
	string secret = "I ain't got no secrets!";
};

void classesAccessLesson()
{
	printf("In this lesson I've created a class called AccessPerson\n");
	printf("This class have the same attributes and methods as ConstructorPerson\n");
	printf("\n");
	printf("The difference is that this class has attributes you can't directly access\n");
	printf("But it does have some public methods which gives you access to the private attributes\n");

	AccessPerson personOne("Ole", 27, "Pizza");
	personOne.printVariables();
	personOne.printSecret();

	printf("\n");
	printf("The default secret for this class is 'I ain't got no secrets!'\n");
	printf("Lets change the default value to a terrible secret\n");
	printf("\n");

	personOne.setSecret("I like to eat in bed :(");
	personOne.printSecret();
}

class EncapsulationPerson : private BasicPerson
{
public:
	void setName(string pName)
	{
		name = pName;
	}

	string getName()
	{
		return name;
	}

	void setAge(int pAge)
	{
		age = pAge;
	}

	int getAge()
	{
		return age;
	}

	void setFavoriteFood(string pFavoriteFood)
	{
		favoriteFood = pFavoriteFood;
	}

	void printAttributes()
	{
		printf("\n");
		printf("Name: %s\n", name.c_str());
		printf("Age: %i\n", age);
		printf("Favorite food: %s\n", favoriteFood.c_str());
	}
};

void classesWithEncapsulationLesson()
{
	EncapsulationPerson personOne;

	printf("In this lesson I've created a class called EncapsulationPerson\n");
	printf("This class have the same attributes as BasicPerson.\n");
	printf("But the attributes from BasicPerson are private\n");
	printf("meaning they cant be accessed directly\n");
	printf("\n");
	printf("The class includes methods for getting and setting the attributes.\n");

	printf("\n");
	printf("I've created a new person using the newly created class, lets look at the default variables\n");
	personOne.printAttributes();

	personOne.setName("Gustav");
	personOne.setAge(69);
	personOne.setFavoriteFood("Lutefisk");

	printf("\n");
	printf("Now I've used the setter methods to change its attributes\n");
	printf("Lets take a look at the updated person\n");
	personOne.printAttributes();
}