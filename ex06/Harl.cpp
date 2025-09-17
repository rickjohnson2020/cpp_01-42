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
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4) {
		if (level == levels[i])
			break;
		i++;
	}
	switch (i) {
		case 0:
			debug();
			std::cout << std::endl;
		case 1:
			info();
			std::cout << std::endl;
		case 2:
			warning();
			std::cout << std::endl;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}