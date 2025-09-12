#include <iostream>

int main() {
	int numBalls = 42;
	int* ptr = &numBalls;
	int& ref = numBalls;

	std::cout << numBalls << " " << *ptr << " " << ref << std::endl;

	*ptr = 21;
	std::cout << numBalls << std::endl;
	ref = 84;
	std::cout << numBalls << std::endl;
	
	return 0;
}