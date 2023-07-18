
#include "ScalarConverter.hpp"

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

void printDouble(const char* scalar, bool isSimple, float floatValue) {
	double doubleValue = 0.0;
	std::cout << "double: ";
	if (isSimple) {
		doubleValue = static_cast<double>(floatValue);
		std::cout << std::fixed << std::setprecision(1) << doubleValue << "\n";
		return;
	}
	std::string str(scalar);
	std::istringstream iss(str);
	if (iss >> doubleValue) {
		if (std::isinf(doubleValue)) {
			if (doubleValue > 0.0) {
				std::cout << "+inf\n";
			}
			else {
				std::cout << "-inf\n";
			}
		}
		else if (std::isnan(doubleValue)) {
			std::cout << "nan\n";
		}
		else {
			std::cout << std::fixed << std::setprecision(1) << doubleValue << "\n";
			return;
		}
	}
	else {
		std::cout << "impossible\n";
	}
}

void printFloat(const char* scalar, bool isSimple, int intValue) {
	float floatValue = 0.0f;
	std::cout << "float: ";
	if (isSimple) {
		floatValue = static_cast<float>(intValue);
		std::cout << std::fixed << std::setprecision(1) << floatValue << "f\n";
		printDouble(scalar, true, floatValue);
		return;
	}
	std::string str(scalar);
	std::istringstream iss(str);
	if (iss >> floatValue) {
		if (std::isinf(floatValue)) {
			if (floatValue > 0.0f) {
				std::cout << "+inff\n";
			}
			else {
				std::cout << "-inff\n";
			}
		}
		else if (std::isnan(floatValue)) {
			std::cout << "nanf\n";
		}
		else {
			std::cout << std::fixed << std::setprecision(1) << floatValue << "f\n";
			printDouble(scalar, true, floatValue);
			return;
		}
	}
	else {
		std::cout << "impossible\n";
	}
	printDouble(scalar, false, floatValue);
}

void printInt(const char* scalar, bool isSimple, char charValue) {
	int intValue = 0;
	std::cout << "int: ";
	if (isSimple) {
		intValue = static_cast<int>(charValue);
		std::cout << intValue << '\n';
		printFloat(scalar, true, intValue);
		return;
	}
	char* end;
	long longValue = std::strtol(scalar, &end, 10);
	if (scalar != end && *end == '\0' && longValue <= INT_MAX && longValue >= INT_MIN) {
		intValue = static_cast<int>(longValue);
		std::cout << intValue << '\n';
		printFloat(scalar, true, intValue);
		return;
	}
	std::cout << "impossible\n";
	printFloat(scalar, false, intValue);
}

void printChar(const char* scalar) {
	char charValue = '\0';
	int intValue;
	std::string str(scalar);
	std::cout << "char: ";
	if (str.length() == 1) {
		intValue = str.at(0);
	}
	else {
		char* end;
		double doubleValue = strtod(scalar, &end);
		if (scalar == end || std::isnan(doubleValue) || std::isinf(doubleValue)) {
			std::cout << "impossible\n";
			printInt(scalar, false, charValue);
			return;
		}
		if (*end == 'f')
			*end = '0';
		intValue = static_cast<int>(doubleValue);
	}
	if (isdigit(intValue))
		intValue = static_cast<int>(intValue - '0');
	if (intValue <= CHAR_MAX || intValue <= CHAR_MIN) {
		if(isprint(intValue)) {
			charValue = static_cast<char>(intValue);
			std::cout << charValue << '\n';
			printInt(scalar, true, charValue);
			return;
		}
		else {
			std::cout << "Non displayable\n";
		}
	}
	else {
		std::cout << "impossible\n";
	}
	printInt(scalar, false, charValue);
}

void ScalarConverter::convert(const char* scalar) {
	printChar(scalar);
	return;
}
