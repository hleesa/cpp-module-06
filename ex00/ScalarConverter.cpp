
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

//bool toChar()



void ScalarConverter::convert(const char* scalar) {

	std::string scalarString(scalar);
	char* end = NULL;
	double doubleValue = strtod(scalar, &end);
	if(!(*end == 0 || std::string(end) == std::string("f") || isascii(*end))) {
		std::cout << *end << ", " << std::string(end) << '\n';
		std::cout << "error\n";
		return ;
	}
	char c = scalarString[0];
	std::cout << "char: " << c << '\n';



	// int

	int intValue = 0;
	long longValue = std::strtol(scalar, &end, 10);
	if (scalar == end) {
		std::cout << "Invalid input: " << scalarString << '\n';
	}
	else if (*end != '\0') {
		std::cout << "Conversion stopped at character: " << *end << '\n';
	}
	else if(longValue > INT_MAX || longValue < INT_MIN) {
		std::cout << "Value exceeds the range of an int\n";
	}
	else {
		intValue = static_cast<int>(longValue);
		std::cout << "int: " << intValue << '\n';
	}

	// int로 변환 됐으면
	float floatValue = static_cast<float>(intValue);
	std::cout << "float: " << floatValue << '\n';

	// 변환 안되면
	std::istringstream iss(scalarString);
	if (iss >> floatValue) {
		if (std::isinf(floatValue)) {
			if (floatValue > log10f(0)) {
				std::cout << "inff\n";
			}
			else {
				std::cout << "-inff\n";
			}
		}
		else if (std::isnan(floatValue)) {
			std::cout << "nanf\n";
		}
		else {
			std::cout << "float: " << floatValue << '\n';
		}
	}
	else {
		std::cout << "conversion fail\n";
	}




	std::cout << "===============================================================\n";
	int imax = INT32_MAX;
	double d = imax + 1;
	int jj = static_cast<int>(d);
	std::cout << imax << '\n';
	std::cout << d << '\n';
	std::cout << jj << '\n';
	std::cout << "double: " << doubleValue << '\n';
}
