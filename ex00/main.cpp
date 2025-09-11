#include "./Zombie.hpp"

int main() {
	Zombie zombie1 = Zombie("zombie1");
	Zombie* zombie2 = new Zombie("zombie2");
	Zombie* zombie3 = newZombie("zombie3");

	zombie1.announce();
	zombie2->announce();
	zombie3->announce();

	randomChump("zombie4");
	delete zombie2;
	delete zombie3;
	return 0;
}