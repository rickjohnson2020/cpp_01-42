#include "./Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG" << std::endl;
	return;
}

void Harl::info() {
	std::cout << "INFO" << std::endl;
	return;
}

void Harl::warning() {
	std::cout << "WARNING" << std::endl;
	return;
}

void Harl::error() {
	std::cout << "ERROR" << std::endl;
	return;
}

Harl::Level Harl::getLevelFromStr(const std::string str) {
	if (str == "DEBUG") return DEBUG;
	if (str == "INFO") return INFO;
	if (str == "WARNING") return WARNING;
	if (str == "ERROR") return ERROR;
	return UNKNOWN;
}

void Harl::complain(std::string level) {
	switch (getLevelFromStr(level)) {
		case DEBUG: 
			debug();
			break;
		case INFO:
			info();
			break;
		case WARNING:
			warning();
			break;
		case ERROR:
			error();
			break;
		default:
			break;;
	}
}