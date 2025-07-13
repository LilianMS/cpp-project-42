#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
: ClapTrap("Default_clap_name")
, ScavTrap("Default")
, FragTrap("Default")
, _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name")
, ScavTrap(name)
, FragTrap(name)
, _name(name)
{
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other)
, ScavTrap(other)
, FragTrap(other)
, _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

// whoAmI()
void DiamondTrap::whoAmI()
{
	std::cout << "🤔 Who am I?" << std::endl;
	std::cout << "🔹 DiamondTrap name: " << _name << std::endl;
	std::cout << "🔸 ClapTrap name:   " << ClapTrap::getName() << std::endl;
}

// const std::string& DiamondTrap::getName() const
// {
// 	return (_name);
// }
