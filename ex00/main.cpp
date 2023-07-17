
#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "No input provided\n";
		return 0;
	}
	ScalarConverter::convert(argv[1]);

}