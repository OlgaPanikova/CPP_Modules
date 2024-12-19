#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();
	void setAttackDamage(unsigned int damage);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
};

#endif