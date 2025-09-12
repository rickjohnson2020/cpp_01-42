#include "../includes/Weapon.hpp"

Weapon::Weapon() {
	return;
}

Weapon::Weapon(std::string type) : _type(type) {
	return;
}

Weapon::~Weapon() {
	return;
}

const std::string& Weapon::getType() const {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}