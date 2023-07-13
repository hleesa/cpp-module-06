
#ifndef CPP_HLEESA_SCALARCONVERTER_HPP
#define CPP_HLEESA_SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>


class ScalarConverter {

public:

	ScalarConverter();

	ScalarConverter(const ScalarConverter& other);

	ScalarConverter& operator=(const ScalarConverter& other);

	~ScalarConverter();

	static void convert(const char* scalar);

};


#endif //CPP_HLEESA_SCALARCONVERTER_HPP
