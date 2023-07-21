
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

void printDouble(double doubleValue, bool isInteger) {
	std::cout << "double: ";
	if (std::isinf(doubleValue)) {
		if (doubleValue > 0.0)
			std::cout << "+inf\n";
		else
			std::cout << "-inf\n";
	}
	else if (std::isnan(doubleValue))
		std::cout << "nan\n";
	else {
		if (isInteger)
			std::cout << std::fixed << std::setprecision(1) << doubleValue << "\n";
		else
			std::cout << doubleValue << "\n";
	}
	return;
}

void printFloat(double doubleValue, bool isInteger) {
	std::cout << "float: ";
	float floatValue = static_cast<float>(doubleValue);
	if (std::isinf(floatValue)) {
		if (floatValue > 0.0f)
			std::cout << "+inff\n";
		else
			std::cout << "-inff\n";
	}
	else if (std::isnan(floatValue))
		std::cout << "nanf\n";
	else {
		if (isInteger)
			std::cout << std::fixed << std::setprecision(1) << floatValue << "f\n";
		else
			std::cout << floatValue << "f\n";
	}
	return;
}

void printInt(long longValue, bool isFloat) {
	std::cout << "int: ";
	if (!isFloat || longValue > INT_MAX || longValue < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(longValue) << '\n';
	return;
}

void printChar(long longValue, bool isFloat) {
	std::cout << "char: ";
	if (!isFloat || longValue > CHAR_MAX || longValue < CHAR_MIN)
		std::cout << "impossible\n";
	else {
		if (isprint(longValue))
			std::cout << static_cast<char>(longValue) << '\n';
		else
			std::cout << "Non displayable\n";
	}
	return;
}

bool isChar(const std::string& scalar) {
	if (scalar.length() == 1 && isascii(scalar.at(0))) {
		return true;
	}
	return false;
}

long toLong(const std::string& scalar, bool& isInteger, double doubleValue) {
	std::stringstream ss(scalar);
	long longValue;
	if (ss >> longValue && doubleValue == static_cast<double>(longValue)) {
		isInteger = true;
	}
	else if (isChar(scalar)) {
		isInteger = true;
		longValue = static_cast<long>(scalar[0]);
		if (isdigit(longValue))
			longValue -= '0';
	}
	return longValue;
}

double toDouble(const std::string& scalar, bool& isFloat) {
	std::stringstream ss(scalar);
	double doubleValue;
	if (ss >> doubleValue || isChar(scalar)) {
		isFloat = true;
	}
	return doubleValue;
}

std::string toString(const char* scalar){
	char* end;
	strtod(scalar, &end);
	if (*end == 'f') {
		*end = '\0';
	}
	return std::string(scalar);
}

void ScalarConverter::convert(const char* scalar) {
	bool isFloat = false;
	bool isInteger = false;
	std::string scalarStr = toString(scalar);
	double doubleValue = toDouble(scalarStr, isFloat);
	long longValue = toLong(scalarStr, isInteger, doubleValue);
	if (!isInteger)
		longValue = static_cast<long>(doubleValue);
	printChar(longValue, isFloat);
	printInt(longValue, isFloat);
	printFloat(doubleValue, isInteger);
	printDouble(doubleValue, isInteger);
	return;
}
