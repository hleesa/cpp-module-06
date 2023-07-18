
#ifndef CPP_HLEESA_SCALARCONVERTER_HPP
#define CPP_HLEESA_SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <iomanip>

class ScalarConverter {

private:

	ScalarConverter();

	ScalarConverter(const ScalarConverter& other);

	ScalarConverter& operator=(const ScalarConverter& other);

	~ScalarConverter();

public:

	static void convert(const char* scalar);

};


#endif //CPP_HLEESA_SCALARCONVERTER_HPP
