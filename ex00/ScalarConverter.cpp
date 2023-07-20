
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

bool isChar(const char* scalar) {
	std::string scalarStr(scalar);
	if (scalarStr.length() == 1 && isascii(scalarStr.at(0))) {
		return true;
	}
	return false;
}

long toLong(const char* scalar, bool& isInteger, double doubleValue) {
	char* end;
	long longValue = std::strtol(scalar, &end, 10);
	if (isChar(scalar)) {
		isInteger = true;
		longValue = static_cast<long>(scalar[0]);
		if (isdigit(longValue))
			longValue -= '0';
	}
	else if (*end == '.')
		isInteger = false;
	else if (longValue == static_cast<long>(doubleValue))
		isInteger = true;
	return longValue;
}

double toDouble(const char* scalar, bool& isFloat) {
	char* end;
	double doubleValue = strtod(scalar, &end);
	if (scalar != end && !std::isnan(doubleValue) && !std::isinf(doubleValue))
		isFloat = true;
	else if (isChar(scalar)) {
		isFloat = true;
		doubleValue = static_cast<double>(scalar[0]);
	}
	return doubleValue;
}

void ScalarConverter::convert(const char* scalar) {
	bool isFloat = false;
	bool isInteger = false;
	double doubleValue = toDouble(scalar, isFloat);
	long longValue = toLong(scalar, isInteger, doubleValue);
	if (!isInteger)
		longValue = static_cast<long>(doubleValue);
//	std::cout << isFloat << '\n';
//	std::cout << isInteger << '\n';
	printChar(longValue, isFloat);
	printInt(longValue, isFloat);
	printFloat(doubleValue, isInteger);
	printDouble(doubleValue, isInteger);
	return;
}
