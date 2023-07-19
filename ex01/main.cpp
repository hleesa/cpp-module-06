
#include "Serializer.hpp"

int main() {
	Data data;
	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	bool isEqual = (deserialized == &data);

	std::cout << isEqual << '\n';
	std::cout << sizeof(data) << '\n';

	return 0;
}
