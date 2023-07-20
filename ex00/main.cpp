
#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "No input provided\n";
		return 0;
	}
//	float f = 42.99;
//	std::cout << f << '\n';
//	std::cout << LONG_MAX << '\n';
//	std::cout << INT_MAX << '\n';
	ScalarConverter::convert(argv[1]);
	return 0;
}
