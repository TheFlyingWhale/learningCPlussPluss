#include <iostream>
#include <fstream>
#include <string>
#include "files.h"
#include "../../utilities/utilities.h"
using namespace std;
using namespace Print;

const string FILES_PATH = "src/lessons/files/generatedFiles/";
const string FILE_NAME = "testFile.txt";

void filesLessonHandler()
{
	printFilesLesson();
	int willTerminate = false;
	while (!willTerminate)
	{
		willTerminate = filesLesson();
	}
}

int filesLesson()
{
	string input = requestInput(requestFilesInput, true);

	if (input == "q")
	{
		return 1;
	}

	if (input == "b")
	{
		filesBasics();
		return 0;
	}

	if (input == "c")
	{
		createTestFile();
		return 0;
	}

	if (input == "r")
	{
		readTestFile();
		return 0;
	}

	if (input == "d")
	{
		deleteTestFile();
		return 0;
	}

	printf("You provided an invalid command");

	return 0;
}

void printFilesLesson()
{
	printf("Welcome to the files lesson\n");
}

void requestFilesInput()
{
	printf("\n");
	printf("Files\n");
	printf("Available commands\n");

	string availableCommands[] = {
		"q - Exit lesson",
		"b - Basics",
		"c - Create test file",
		"r - Read test file",
		"d - Delete test file"};

	for (string command : availableCommands)
	{
		printf("\t%s\n", command.c_str());
	}
}

string filePath(const string fileName, const string path)
{
	return path + fileName;
}

void filesBasics()
{
	printf("The basics of working with files\n");
	printf("C++ offers ofstream, ifstream an fstream.\n");
	newline();
	printf("ofstream(output file stream):\n");
	printf("Is used for creating and writing to files.\n");
	newline();
	printf("ifstream(input file stream):\n");
	printf("Is used for reading files.\n");
	newline();
	printf("fstream(file stream)\n");
	printf("Is a base class for interacting with the file system.\n");
	printf("This means that ofstream and ifstream inherits fstream,\n");
	printf("but are tailor made for their purpose.\n");
};

void createTestFile()
{
	ofstream file(filePath("testFile.txt", FILES_PATH));
	file << "You've just created a test file!";
	file.close();

	success("File created " + FILES_PATH + FILE_NAME);
};

void readTestFile()
{
	ifstream file(filePath(FILE_NAME, FILES_PATH));
	if (!file)
	{
		error("Failed to open file");
		return;
	}

	string text;
	print("Contents of " + FILES_PATH + FILE_NAME + ":");
	newline();
	while (getline(file, text))
	{
		print(text);
	}
	file.close();

	newline();
	printf("If you want to spice things up, manipulate the file directly and run this command again.\n");
}

void deleteTestFile()
{
	bool exists = !!ifstream(filePath(FILE_NAME, FILES_PATH));
	if (!exists)
	{
		error("File does not exist");
		return;
	}

	remove(filePath(FILE_NAME, FILES_PATH).c_str());

	bool failed = !!ifstream(filePath(FILE_NAME, FILES_PATH));
	if (failed)
	{
		error("Failed to delete the file");
		return;
	}

	success("File deleted");
}
