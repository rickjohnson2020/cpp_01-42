#include "./Harl.hpp"

int main() {
	Harl harl = Harl();

	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("some random something");

	return 0;
}