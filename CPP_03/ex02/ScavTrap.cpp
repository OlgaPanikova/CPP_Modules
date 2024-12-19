#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	name= "Meow";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap parametric constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " <<this->name << " no attack points" << std::endl;
		return;
	}
	if (this->energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " no energy points" << std::endl;
		return;
	}
	else {
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
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

void ScavTrap:: guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}