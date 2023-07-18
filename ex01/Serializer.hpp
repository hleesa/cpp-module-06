
#ifndef CPP_HLEESA_SERIALIZER_HPP
#define CPP_HLEESA_SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {

private:
	Serializer();

	Serializer(const Serializer& other);

	Serializer& operator=(const Serializer& other);

	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);

};


#endif //CPP_HLEESA_SERIALIZER_HPP
