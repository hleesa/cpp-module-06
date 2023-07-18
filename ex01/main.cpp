
#include "Serializer.hpp"

int main() {
	Data data(42);
	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	bool isEqual = (deserialized == &data);

	std::cout << isEqual << '\n';

	return 0;
}
