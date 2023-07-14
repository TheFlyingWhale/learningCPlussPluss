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

	if (input == "i")
	{
		classesWithInheritanceLesson();
		return 0;
	}

	if (input == "im")
	{
		classesWithMultipleInheritance();
		return 0;
	}

	if (input == "as")
	{
		classesWithAccessSpecifiers();
		return 0;
	}

	if (input == "p")
	{
		classesWithPolymorphism();
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
	printf("Classes\n");
	printf("Available commands\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"b - Basic lesson",
		"m - Methods",
		"c - Constructors",
		"a - Access specifiers",
		"e - Encapsulation",
		"i - Inheritance",
		"im - Multiple inheritances",
		"as - Access specifiers vol.2",
		"p - Polymorphism"};

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
private:
	string secret = "I ain't got no secrets!";

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

	void setAge(int pAge)
	{
		age = pAge;
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

void classesWithInheritanceLesson()
{
	printf("Inheritance enables us to create blueprints which other classes can use\n");
	printf("I've pretty much jumped the gun on this one since all classes in these lessons have inherited the BasicPerson class\n");
	printf("It lets us create variants of familiar objects, focusing on the differences rather than whats shared.\n");
	printf("\n");
	printf("There is also multilevel inheritance.\n");
	printf("It's when a third class inherits a second class which inherits a first class. Classception.\n");
	printf("So is the case with ConstructorClass, which inherits MethodClass, which inherits BasicClass.\n");
}

class WithMoreFavoritesPerson
{
protected:
	string favoriteArtist = "No favorite artist";
	string favoriteColor = "No favorite color";
	int favoriteNumber = 0;

public:
	void setFavoriteArtist(string fArtist)
	{
		favoriteArtist = fArtist;
	}

	void setFavoriteColor(string fColor)
	{
		favoriteColor = fColor;
	}

	void setFavoriteNumber(int fNumber)
	{
		favoriteNumber = fNumber;
	}
};

class MultipleInheritancePerson : public BasicPerson, public WithMoreFavoritesPerson
{
public:
	void setName(string pName)
	{
		name = pName;
	}
	void setAge(int pAge)
	{
		age = pAge;
	}
	void setFavoriteFood(string pFavoriteFood)
	{
		favoriteFood = pFavoriteFood;
	}

	void printAttributes()
	{
		printf("\n");
		printf("Name: %s\n", name.c_str());
		printf("Age: %u\n", age);
		printf("Favorite food: %s\n", favoriteFood.c_str());
		printf("Favorite color: %s\n", favoriteColor.c_str());
		printf("Favorite artist: %s\n", favoriteArtist.c_str());
		printf("Favorite number: %i\n", favoriteNumber);
	}
};

void classesWithMultipleInheritance()
{
	printf("Multiple inheritance\n");
	printf("Enables us to create several classes that other classes may and may not have in common\n");

	printf("\n");
	printf("In this lesson I've created two classes:\n");
	printf("\tWithMoreFavoritesPerson\n");
	printf("\tMultipleInheritancePerson\n");

	printf("\n");
	printf("The first one is the same as the BasicPerson class, but with more favorites, and setter methods.\n");
	printf("The last one extends the classes BasicPerson and WithMoreFavoritesPerson,\n");
	printf("it also have setter methods for the attributes in BasicPerson, as well as a printAttributes method\n");

	printf("\n");
	printf("Lets take a look at the MultipleInheritancePerson class without setting any attributes:\n");
	MultipleInheritancePerson perOne;
	perOne.printAttributes();

	printf("\n");
	printf("Now let us use all the setters and take another look:\n");
	perOne.setName("Knut");
	perOne.setAge(43);
	perOne.setFavoriteFood("Cheese burger");
	perOne.setFavoriteArtist("Melokind");
	perOne.setFavoriteColor("Blue");
	perOne.setFavoriteNumber(69);
	perOne.printAttributes();
}

void classesWithAccessSpecifiers()
{
	printf("I've already created a lesson for Access Specifiers.\n");
	printf("But in that lesson we just used Public and Private. But there is a third one, Protected.\n");

	printf("\n");
	printf("- Public: Lets us access the attributes or methods from outside of the class.\n");
	printf("- Private: Prohibits any access outside of the class.\n");
	printf("- Protected: Gives only inheriting classes access the methods or attributes\n");

	printf("\n");
	printf("In the classesWithMultipleInheritance we created the class MultipleInheritancePerson,\n");
	printf("which inherits the BasicPerson and WithMoreFavoritesPerson classes\n");
	printf("BasicPerson have its attributes public,\n");
	printf("which lets me manipulate the object from the outside.\n");
	printf("WithMoreFavoritesPerson have its attributes protected,\n");
	printf("which prohibits me from manipulating the attributes from the outside.\n");
	printf("But since they're protected, the MultipleInheritanceClass have access to the attributes,\n");
	printf("which lets me create and use the setter methods.\n");
}

class NationalityPerson
{
protected:
	string name = "Person has no name";

public:
	void sayHello()
	{
		printf("The person says hello\n");
	}

	void setName(string pName)
	{
		name = pName;
	}
};

class NorwegianPerson : public NationalityPerson
{
public:
	void sayHello()
	{
		printf("Hei, mitt navn er %s\n", name.c_str());
	}
};

class EnglishPerson : public NationalityPerson
{
public:
	void sayHello()
	{
		printf("Hello, my name is %s\n", name.c_str());
	}
};

class ItalianPerson : public NationalityPerson
{
public:
	void sayHello()
	{
		printf("Ciao, mi chiamo %s\n", name.c_str());
	}
};

void classesWithPolymorphism()
{
	printf("Polymorphism\n");
	printf("Lets us override inherited methods or attributes.\n");
	printf("In this lesson I've created the NationalityPerson class.\n");
	printf("This class has a private name attribute and two methods; setName and sayHello\n");

	printf("\n");
	printf("These classes prints a hello message in their respective language, followed by their name\n");

	printf("\n");
	printf("Lets start with the NationalityPerson class.\n");
	printf("Without calling the setName method, lets se what the sayHello method does.\n");
	NationalityPerson perOne;
	perOne.sayHello();

	printf("\n");
	printf("Ok, nothing interesting to say. Now lets try the NorwegianPerson class\n");
	printf("This and the following classes inherits the NationalityPerson class, but morphs its sayHello method.");
	printf("In all the following examples I'll be using setName give them the name Pål");
	printf("Now lets se what NorwegianPerson has to say:\n");
	NorwegianPerson perTwo;
	perTwo.setName("Pål");
	perTwo.sayHello();

	printf("\n");
	printf("EnglishPerson:\n");
	EnglishPerson perThree;
	perThree.setName("Pål");
	perThree.sayHello();

	printf("\n");
	printf("ItalianPerson:\n");
	ItalianPerson perFour;
	perFour.setName("Pål");
	perFour.sayHello();
}