#ifndef PRINT_LINE
#define PRINT_LINE
using namespace std;

// Passes the provided parameter to std::out
template <typename T>
void print(const T inOne)
{
	cout << inOne << endl;
}

void newLine();

void printMath(string description, int result);

#endif