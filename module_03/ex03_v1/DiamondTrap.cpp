#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() 
	: ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "💎 DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "💎 DiamondTrap constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "💎 DiamondTrap copy constructor called for " << _name << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "💎 DiamondTrap assignment operator called\n";
	if (this != &other) {
		_name = other._name;
		ClapTrap::operator=(other);
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "💎 DiamondTrap destructor called for " << _name << "\n";
}

// whoAmI method
void DiamondTrap::whoAmI()
{
	std::cout << "🤔 Who am I?\n";
	std::cout << "🔹 DiamondTrap name: " << _name << "\n";
	std::cout << "🔸 ClapTrap name: " << ClapTrap::_name << "\n";
}
