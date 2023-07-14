#ifndef REQUEST_INPUT
#define REQUEST_INPUT

std::string requestInput(string prompt = "", bool clearAfterPrompt = false);
std::string requestInput(void (*func)(), bool clearAfterPrompt = false);
void clearTerminal();

#endif