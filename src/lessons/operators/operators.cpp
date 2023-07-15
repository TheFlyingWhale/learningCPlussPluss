#include <iostream>
#include "../../utilities/utilities.h"
#include "operators.h"
using namespace std;
using namespace Print;

int x = 10;
int y = 5;

void printOperatorsLesson()
{
	print("Operators");
	print("Are used to preform such as Arithmetics, Assignment, Comparison and Logic");
	newline();

	print("In this lesson I'll be using two variables X and Y");
	print("The X variable is set to be of int 10");
	print("The Y variable is set to be of int 5");
	newline();

	printOperationsArithmetics();
	printAssignmentOperators();
	printComparisonOperators();
}

void printOperationsArithmetics()
{
	print("Lets start of with Arithmetic Operators");
	print("Arithmetic means to manipulate numbers");
	print("- Multiplication, adding two numbers together");
	math("x + y", x + y);
	newline();

	print("- Subtraction, taking a amount from another");
	math("x - y", x - y);
	newline();

	print("- Multiplication, multiply a value with itself an amount of times");
	math("x * y", x * y);
	newline();

	print("- Division, Splitting a number into equal parts");
	math("x / y", x / y);
	newline();

	print("- Increment, Increasing a number by a fixed amount");
	math("++x", ++x);
	newline();

	print("Decrement, Decreasing a number by a fixed amount");
	math("--x", --x);
	print("This resulted in 10 because we incremented it first");
	newline();
}

void printAssignmentResult(string description)
{
	cout << description << " == x = " << x << endl;
}

void printAssignmentOperators()
{
	print("Assignment Operators");
	print("These operators assign values to variables");
	print("When I created the X and Y variables I assigned them using the (=) operator");
	print("You will se examples where I reassign the X variable, then see the result");
	x = 20;
	printAssignmentResult("x = 20");

	x += 5;
	printAssignmentResult("x +- 5");

	x -= 10;
	printAssignmentResult("x -= 10");

	x *= 10;
	printAssignmentResult("x *= 10");

	x /= 2;
	printAssignmentResult("x /= 2");

	x %= 7;
	printAssignmentResult("x %= 7");

	x &= 3;
	printAssignmentResult("x &= 3");

	x |= 4;
	printAssignmentResult("x |= 3");

	x ^= 2;
	printAssignmentResult("x ^= 2");

	x >>= 1;
	printAssignmentResult("x >>= 1");

	x <<= 2;
	printAssignmentResult("x <<= 2");
	newline();

	x = 10;
}

void printComparisonResult(string description, bool result)
{
	string isTrue = result ? "true" : "false";

	cout << x << " " << description << " " << y << " == "
		 << isTrue << endl;
}

void printComparisonOperators()
{
	print("Comparison Operators");
	print("These operators compare values");
	print("The result of a comparison always result in a boolean answer, true or false");
	printComparisonResult("==", x == y);
	printComparisonResult("!=", x != y);
	printComparisonResult(">", x > y);
	printComparisonResult("<", x < y);
	printComparisonResult(">=", x >= y);
	printComparisonResult("<=", x <= y);
	newline();
}