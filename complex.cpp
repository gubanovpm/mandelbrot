#include "complex.hpp"

int main() {
	Complex_t z1 = {3, 7};
	Complex_t z2 = {2, -4};

	Complex_t z = z1 + z2;
	std::cout << z << std::endl;

	z = z * 5;
	std::cout << z << std::endl;

	z = z1 - z2;
	std::cout << z << std::endl;
	z = z1 * z2;
	std::cout << z << std::endl;
	z = z1 / z2;
	std::cout << z << std::endl;
	z = -z1;
	std::cout << z << std::endl;
	z = ~z1;
	std::cout << z << std::endl;
	z = exp(z1 + z2)/(z1 * z2);
	std::cout << z << std::endl;
	return 0;

}