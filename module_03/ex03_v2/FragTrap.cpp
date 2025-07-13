#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "FragTrap named constructor called for " << _name << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);

}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name
			<< " says: High fives, guys! ✋" << std::endl;
}
