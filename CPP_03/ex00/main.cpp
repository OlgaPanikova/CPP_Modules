#include "ClapTrap.hpp"

int main() {

	ClapTrap One("Karl");
	ClapTrap Two("Mark");

	// One.attack("Mark");
	// Two.takeDamage(1);
	// Two.beRepaired(2);
	// Two.attack("Karl");
	// One.takeDamage(3);
	// One.beRepaired(2);

	for (int i = 0; i < 11; i++) {
		One.attack("Mark");
		Two.takeDamage(1);
}

	One.beRepaired(5);
	Two.beRepaired(5);

	One.attack("Mark");

	return 0;
}
