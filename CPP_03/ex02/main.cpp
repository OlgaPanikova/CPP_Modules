
#include "FragTrap.hpp"

int main() {

	FragTrap Defult;
	FragTrap One("Karl");
	ScavTrap Two("Mark");
	One.attack("Mark");
	Two.takeDamage(30);
	Two.beRepaired(10);
	Two.guardGate();
	One.attack("ScavTrap");
	Two.takeDamage(15);
	One.highFivesGuys();
	return 0;
}
