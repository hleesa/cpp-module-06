#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generate(void) {
	int random = std::rand() % 3;
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return 0;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != 0) {
		std::cout << "A\n";
	}
	else if (dynamic_cast<B*>(p) != 0) {
		std::cout << "B\n";
	}
	else if (dynamic_cast<C*>(p) != 0) {
		std::cout << "C\n";
	}
}

void identify(Base& p) {
	identify(&p);
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base* object = generate();
	identify(object);
	return 0;
}
