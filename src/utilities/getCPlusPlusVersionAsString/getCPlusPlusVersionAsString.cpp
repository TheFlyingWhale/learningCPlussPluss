#include <string>
#include "getCPlusPlusVersionAsString.h"

std::string getCPlusPlusVersionAsString()
{
	switch (__cplusplus)
	{
	case 199711L:
		return "C++98/03";
	case 201103L:
		return "C++11";
	case 201402L:
		return "C++14";
	case 201703L:
		return "C++17";
	case 201709L:
		return "CPP20";
	default:
		return "Unknown";
	}
}