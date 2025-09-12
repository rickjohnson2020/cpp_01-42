#include <iostream>

void increment1(int& ref) {
	ref++;
}

void increment2(int value) {
	value++;
}


int main() {
	int value = 42;
	// int& ref = value;

	increment1(value);
	increment1(value);
	std::cout << value << std::endl;
	return 0;
}