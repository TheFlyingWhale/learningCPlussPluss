#include <iostream>
#include "../terminator/terminator.h"
#include "../../constants.h"

#ifndef HELPERS
#define HELPERS

using namespace std;

int commandHandler(ProcessConstants::ProcessName process);
string requestCommand(ProcessConstants::ProcessName process);
int lessonCommandHandler(string input);

int displayCommands(bool invalidCommand, ProcessConstants::ProcessName process);
void displayInvalidCommand();
void displayCommandsTitle(string title);
void displayDefaultCommands();
void displayMainCommands();
void displayLessonCommands();

int printProvidedInput(string input);

#endif