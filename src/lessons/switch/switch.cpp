#include <iostream>
#include <map>
#include "switch.h"
#include "../../utilities/utilities.h"
using namespace std;

string switchInput = "";
bool willSwitchLessonTerminate = false;
map<string, int> smileys;

void switchLessonHandler()
{
	initialiseSmileyMap();
	printSwitchLesson();
	willSwitchLessonTerminate = false;
	while (!willSwitchLessonTerminate)
	{
		willSwitchLessonTerminate = switchLesson();
	}
}

void printSwitchLesson()
{
	system("clear");
	print("Switch Statements");
	print("Are basically a series of If Statements, but with its own syntax");
	print("In this lesson I'm using a switch statement to react to your mood!");
	newLine();
}

void initialiseSmileyMap()
{
	smileys[":)"] = 1;
	smileys[":("] = 2;
	smileys[":/"] = 3;
	smileys[":o"] = 4;
	smileys[":0"] = 4;
}

int determineSmileyMapInt(string input)
{
	auto iterator = smileys.find(input);
	if (iterator != smileys.end())
	{
		return iterator->second;
	}
	return 0;
}

int switchLesson()
{
	string input = requestSmileyInput();
	if (input[0] == 'q')
	{
		system("clear");
		return 1;
	}

	system("clear");
	switch (determineSmileyMapInt(input))
	{
	case 1:
		print("Nice, your happy!");
		newLine();
	case 2:
		print("Aww, don't me sad. Thinking about puppies might improve your mood!");
		newLine();
	case 3:
		print("Hmmm...");
		newLine();
	case 4:
		print("Wow, whats the surprise?!");
		break;
	default:
		print("Thats an invalid smiley, or no smiley at all! Try again");
	}

	return 0;
}

string requestSmileyInput()
{
	newLine();
	print("Provide a smiley - or 'q' to exit lesson");
	string input = "";
	getline(cin, input);
	return input;
}