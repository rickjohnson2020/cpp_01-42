#include "./Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
	std::cout << "[ DEBUG ]\n"
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
			  << "I really do!\n";
	return;
}

void Harl::info() {
	std::cout << "[ INFO ]\n"
			  << "I cannot believe adding extra bacon costs more money.\n"
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	return;
}

void Harl::warning() {
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve to have some extra bacon for free.\n"
			  << "I've been coming for years, whereas you started working here just last month.\n";
	return;
}

void Harl::error() {
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable! I want to speak to the manager now.\n";
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
	std::cout << "[ Unknown ]" << std::endl;
}