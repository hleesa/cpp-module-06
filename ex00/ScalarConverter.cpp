
#include "ScalarConverter.hpp"

#include <string>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}


void toChar(std::string value) {
	if (value.length() == 1) {
		char charValue = static_cast<char>(value[0]);
		if (isprint(charValue)) {
			std::cout << "char: " << charValue << '\n';
		}
		else{
			std::cout << "Non displayable"  << '\n';
		}
	}
	else {
		std::cout << "Non displayable"  << '\n';
	}
	return ;
}

void toInt(double doubleValue) {
	int intValue = static_cast<int>(doubleValue);
	std::cout << "int: " << intValue << '\n';
}

//void toFloat(double )

void ScalarConverter::convert(const char* scalar) {

	std::string scalarString(scalar);
	char* end = NULL;
	double doubleValue = strtod(scalar, &end);
	if(!(end == NULL || std::string(end) == std::string("f"))) {
		std::cout << "error\n";
		return ;
	}
//	size_t l = strlen(scalar);
//
//	std::cout << "----------------------------\n";
//	std::cout << doubleValue << '\n';
//	printf("%s\n", (scalar+l));
//	if (endString == "f") {
//		std::cout << "same\n";
//	}
//	else {
//		std::cout << "diff\n";
//	}
//	printf("%s\n", (end));
//	std::cout << end << '\n';
//	std::cout << "----------------------------\n";
//
//	if (doubleValue != 0.0) {
//		int intValue = static_cast<int>(doubleValue);
//		if (value.find('.') != std::string::npos) {
//			float floatValue = static_cast<float>(doubleValue);
//			std::cout << "float: " << floatValue << '\n';
//		}
//	}
	std::cout << "double: " << doubleValue << '\n';
}
