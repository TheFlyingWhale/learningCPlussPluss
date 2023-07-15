#ifndef PRINT_LINE
#define PRINT_LINE
using namespace std;

namespace Print
{
	template <typename T>
	void print(const T inOne)
	{
		cout << inOne << endl;
	}

	void newline();

	void math(string description, int result);

	void error(string message);

	void success(string message);
};

#endif