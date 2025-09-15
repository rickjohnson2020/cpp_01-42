#include "./Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG message" << std::endl;
	return;
}

void Harl::info() {
	std::cout << "INFO message" << std::endl;
	return;
}

void Harl::warning() {
	std::cout << "WARNING message" << std::endl;
	return;
}

void Harl::error() {
	std::cout << "ERROR message" << std::endl;
	return;
}

void Harl::complain(std::string level) {
	typedef void (Harl::*FuncPtr)(void);
	FuncPtr funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << "Unknown level" << std::endl;
}