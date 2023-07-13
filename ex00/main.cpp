
#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "No input provided\n";

		const char* charStr = "A";
		std::string stringStr = "65";

		// Convert char* to char
		int intValue;
		char charValue;
		std::istringstream(charStr) >> intValue;
		charValue = static_cast<char>(intValue);
		std::cout << "Char value: " << charValue << std::endl;

		// Convert std::string to int
		std::istringstream(stringStr) >> intValue;
		std::cout << "Int value: " << intValue << std::endl;

		return 0;
	}
	ScalarConverter::convert(argv[1]);

}