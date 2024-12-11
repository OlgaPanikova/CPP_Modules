
#include "ScavTrap.hpp"

int main() {
	ScavTrap defaultScavTrap;
	ScavTrap One("Karl");
	ScavTrap Two("Mark");
	One.attack("Mark");
	Two.takeDamage(30);
	Two.beRepaired(10);
	Two.guardGate();
	One.attack("ScavTrap");
	defaultScavTrap.takeDamage(15);
	ScavTrap Temp = One;
	return 0;
}
