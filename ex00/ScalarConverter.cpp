
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

void printDouble(const char* scalar, bool& isDirectCast, float floatValue) {
	double doubleValue = 0.0;
	std::cout << "double: ";
	if (isDirectCast) {
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

float printFloat(const char* scalar, bool& isDirectCast, int intValue) {
	float floatValue = 0.0f;
	std::cout << "float: ";
	if (isDirectCast) {
		floatValue = static_cast<float>(intValue);
		std::cout << std::fixed << std::setprecision(1) << floatValue << "f\n";
		isDirectCast = true;
		return floatValue;
	}
	isDirectCast = false;
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
			isDirectCast = true;
			return floatValue;
		}
	}
	else {
		std::cout << "impossible\n";
	}
	return floatValue;
}

int printInt(const char* scalar, bool& isDirectCast, char charValue) {
	int intValue = 0;
	std::cout << "int: ";
	if (isDirectCast) {
		intValue = static_cast<int>(charValue);
		std::cout << intValue << '\n';
		isDirectCast = true;
		return intValue;
	}
	isDirectCast = false;
	char* end;
	long longValue = std::strtol(scalar, &end, 10);
	if (scalar != end && *end == '\0' && longValue <= INT_MAX && longValue >= INT_MIN) {
		intValue = static_cast<int>(longValue);
		std::cout << intValue << '\n';
		isDirectCast = true;
		return intValue;
	}
	std::cout << "impossible\n";
	return intValue;
}

char printChar(const char* scalar, bool& isDirectCast) {
	char charValue = '\0';
	int intValue;
	std::cout << "char: ";
	char* end;
	double doubleValue = strtod(scalar, &end);
	if (scalar == end || std::isnan(doubleValue) || std::isinf(doubleValue)) {
		std::cout << "impossible\n";
		return charValue;
	}
	if (*end == 'f') {
		*end = '\0';
		if (*(end + 1) != '\0') {
			std::cout << "impossible\n";
			return charValue;
		}
	}
	intValue = static_cast<int>(doubleValue);
	if (isdigit(intValue))
		intValue = static_cast<int>(intValue - '0');
	if (intValue <= CHAR_MAX || intValue <= CHAR_MIN) {
		if (isprint(intValue)) {
			charValue = static_cast<char>(intValue);
			std::cout << charValue << '\n';
			isDirectCast = true;
			return charValue;
		}
		else {
			std::cout << "Non displayable\n";
		}
	}
	else {
		std::cout << "impossible\n";
	}
	return charValue;
}

void ScalarConverter::convert(const char* scalar) {
	bool isDirectCast = false;
	char charValue = printChar(scalar, isDirectCast);
	int intValue = printInt(scalar, isDirectCast, charValue);
	float floatValue = printFloat(scalar, isDirectCast, intValue);
	printDouble(scalar, isDirectCast, floatValue);
	return;
}
