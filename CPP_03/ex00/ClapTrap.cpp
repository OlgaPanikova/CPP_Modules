#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Henry"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints <= 0) {
		std::cout << this->name << " no attack points" << std::endl;
		return;
	}
	if (this->energyPoints <= 0) {
		std::cout << this->name << " no energy points" << std::endl;
		return;
	}
	else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if(this->hitPoints <= 0) {
		std::cout << this->name << " the attack is impossible because he has no hit points left!" << std::endl;
		return;
	}
	this->hitPoints -= amount;
	if(this->hitPoints < 0) {
		this->hitPoints = 0;
	}
	std::cout << this->name << " received " << amount << " units of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(this->hitPoints <= 0) {
		std::cout << this->name << " cannot be repaired because it has no hit points left!" << std::endl;
		return;
	}
	if(this->energyPoints <= 0) {
		std::cout << this->name << " does not have enough energy points to recover" << std::endl;
		return;
	}
	if(this->hitPoints + amount > 10) {
		this->hitPoints = 10;
		std::cout << this->name << " repaired" << " max points" << std::endl;
	}
	else {
		this->hitPoints += amount;
		std::cout << this->name << " repaired" << " for " << amount << " points" << std::endl;
	}
	this->energyPoints -= 1;
}