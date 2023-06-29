#include "../terminator/terminator.h"
#include "../../constants.h"
#include <iostream>

#ifndef HELPERS
#define HELPERS

using namespace std;

int commandHandler(ProcessConstants::ProcessType process);
string requestCommand(ProcessConstants::ProcessType process);
int lessonCommandHandler(string input);

int displayCommands(bool invalidCommand, ProcessConstants::ProcessType process);
void displayInvalidCommand();
void displayCommandsTitle(string title);
void displayDefaultCommands();
void displayMainCommands();
void displayLessonCommands();

int printProvidedInput(string input);

#endif