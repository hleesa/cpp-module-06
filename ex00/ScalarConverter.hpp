
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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


#endif //SCALARCONVERTER_HPP
