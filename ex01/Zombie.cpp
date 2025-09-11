#include <iostream>
#include <string>
#include "./Zombie.hpp"

Zombie::Zombie() : _name("noname") {
	std::cout << _name << " created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << _name << " created" << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << _name << " destroyed" << std::endl;
	return;
}

void Zombie::setName(std::string name) {
	_name = name;
	std::cout << _name << " is set" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}