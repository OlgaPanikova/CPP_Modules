#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	name = "Woof";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap parametric constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->hitPoints <= 0) {
		std::cout << this->name << " no attack points" << std::endl;
		return;
	}
	if (this->energyPoints <= 0) {
		std::cout << this->name << " no energy points" << std::endl;
		return;
	}
	else {
		std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if(this->hitPoints <= 0) {
		std::cout << this->name << " cannot be repaired because it has no hit points left!" << std::endl;
		return;
	}
	if(this->energyPoints <= 0) {
		std::cout << this->name << " does not have enough energy points to recover" << std::endl;
		return;
	}
	if(this->hitPoints + amount > 100) {
		this->hitPoints = 100;
		std::cout << this->name << " repaired" << " max points" << std::endl;
	}
	else {
		this->hitPoints += amount;
		std::cout << this->name << " repaired" << " for " << amount << " points" << std::endl;
	}
	this->energyPoints -= 1;
}