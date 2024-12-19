
#include "ScavTrap.hpp"

int main() {
	
	// ScavTrap defaultScavTrap;
	ClapTrap* Misha = new ScavTrap();
	// ScavTrap One("Karl");
	// ScavTrap Two("Mark");
	// One.attack("Mark");
	// Two.takeDamage(30);
	// Two.beRepaired(10);
	// Two.guardGate();
	// One.attack("ScavTrap");
	// defaultScavTrap.takeDamage(15);
	// ScavTrap Temp = One;
	Misha->attack("Hayk");
	Misha->takeDamage(90);
	Misha->beRepaired(20);
	delete Misha;
	return 0;
}
