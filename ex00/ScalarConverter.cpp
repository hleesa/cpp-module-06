
#include "ScalarConverter.hpp"

enum eType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

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

void printDouble(double value) {
	std::cout << "double: ";
	if (isinf(value)) {
		if (value > 0.0)
			std::cout << "+inf\n";
		else
			std::cout << "-inf\n";
	}
	else if (isnan(value))
		std::cout << "nan\n";
	else
		std::cout << value << "\n";
	return;
}

void printFloat(float value) {
	std::cout << "float: ";
	if (isinf(value)) {
		if (value > 0.0f)
			std::cout << "+inff\n";
		else
			std::cout << "-inff\n";
	}
	else if (isnan(value))
		std::cout << "nanf\n";
	else
		std::cout << value << "f\n";
	return;
}

void printInt(int value, double doubleValue, bool isPossible) {
	std::cout << "int: ";
	if (!isPossible || isnan(doubleValue) || isinf(doubleValue))
		std::cout << "impossible\n";
	else
		std::cout << value << '\n';
	return;
}

void printChar(char value, double doubleValue, bool isPossible) {
	std::cout << "char: ";
	if (!isPossible || value > CHAR_MAX || value < CHAR_MIN || isnan(doubleValue) || isinf(doubleValue))
		std::cout << "impossible\n";
	else {
		if (isprint(value))
			std::cout << "'" << value << "'" << '\n';
		else
			std::cout << "Non displayable\n";
	}
	return;
}

void print(char charValue, int intValue, float floatValue, double doubleValue, bool isPossible) {
	printChar(charValue, doubleValue, isPossible);
	printInt(intValue, doubleValue, isPossible);
	printFloat(floatValue);
	printDouble(doubleValue);
}

double toDouble(const char* scalar, bool& isPossible) {
	std::string scalarStr(scalar);
	std::stringstream ss(scalarStr);
	double value;
	isPossible = ss >> value;
	return value;
}

void printDouble(const char* scalar) {
	bool isPossible = true;
	double doubleValue = toDouble(scalar, isPossible);
	char charValue = static_cast<char>(doubleValue);
	int intValue = static_cast<int>(doubleValue);
	float floatValue = static_cast<int>(doubleValue);
	print(charValue, intValue, floatValue, doubleValue, isPossible);
	return;
}

float toFloat(const char* scalar, bool& isPossible) {
	std::string scalarStr(scalar);
	scalarStr.at(scalarStr.length() - 1) = '\0';
	std::stringstream ss(scalarStr);
	float value;
	isPossible = ss >> value;
	return value;
}

void printFloat(const char* scalar) {
	bool isPossible;
	float floatValue = toFloat(scalar, isPossible);
	double doubleValue = static_cast<double>(floatValue);
	char charValue = static_cast<char>(floatValue);
	int intValue = static_cast<int>(floatValue);
	print(charValue, intValue, floatValue, doubleValue, isPossible);
	return;
}

int toInt(const char* scalar, bool& isPossible) {
	std::string scalarStr(scalar);
	std::stringstream ss(scalarStr);
	int value;
	isPossible = ss >> value;
	return value;
}

void printInt(const char* scalar) {
	bool isPossible;
	int intValue = toInt(scalar, isPossible);
	float floatValue = static_cast<float>(intValue);
	double doubleValue = static_cast<double>(intValue);
	char charValue = static_cast<char>(intValue);
	print(charValue, intValue, floatValue, doubleValue, isPossible);
	return;
}

char toChar(const char* scalar) {
	return scalar[0];
}

void printChar(const char* scalar) {
	bool isPossible = true;
	char charValue = toChar(scalar);
	int intValue = static_cast<int>(charValue);
	float floatValue = static_cast<float>(charValue);
	double doubleValue = static_cast<double>(charValue);
	print(charValue, intValue, floatValue, doubleValue, isPossible);
	return;
}

bool isFloat(const std::string& scalar) {
	return scalar[scalar.length() - 1] == 'f';
}

bool isInt(const std::string& scalar) {
	for (size_t i = 0; i < scalar.length(); ++i) {
		if (!isdigit(scalar[i]))
			return false;
	}
	return true;
}

bool isChar(const std::string& scalar) {
	return scalar.length() == 1 && isascii(scalar.at(0)) && !isdigit(scalar.at(0));
}

enum eType detectType(const char* scalar) {
	std::string scalarStr(scalar);
	if (isChar(scalarStr))
		return CHAR;
	else if (isInt(scalarStr))
		return INT;
	else if (isFloat(scalar))
		return FLOAT;
	else
		return DOUBLE;
}

void ScalarConverter::convert(const char* scalar) {
	switch (detectType(scalar)) {
		case CHAR:
			printChar(scalar);
			break;
		case INT:
			printInt(scalar);
			break;
		case FLOAT:
			printFloat(scalar);
			break;
		case DOUBLE:
			printDouble(scalar);
			break;
	}
	return;
}
