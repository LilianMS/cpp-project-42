#include "DiamondTrap.hpp"
#include <iostream>

// Definição da variável global
DiamondTrapValues g_diamondValues;

DiamondTrap::DiamondTrap()
: ClapTrap("Default_clap_name")
, ScavTrap("Default")
, FragTrap("Default")
, _name("Default")
{
	// Usa os valores capturados pelas classes base na estrutura global
	setHitPoints(g_diamondValues.fragTrapHP);      // HP capturado do FragTrap
	setEnergyPoints(g_diamondValues.scavTrapEP);   // Energy capturado do ScavTrap
	setAttackDamage(g_diamondValues.fragTrapAD);   // Attack capturado do FragTrap
	
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name")
, ScavTrap(name)
, FragTrap(name)
, _name(name)
{
	// Usa os valores capturados pelas classes base na estrutura global
	setHitPoints(g_diamondValues.fragTrapHP);      // HP capturado do FragTrap
	setEnergyPoints(g_diamondValues.scavTrapEP);   // Energy capturado do ScavTrap
	setAttackDamage(g_diamondValues.fragTrapAD);   // Attack capturado do FragTrap

	std::cout << "DiamondTrap constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other)
, ScavTrap(other)
, FragTrap(other)
, _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called for " << _name << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called\n";
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << "\n";
}

// override de attack() → usa ScavTrap::attack
void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

// whoAmI()
void DiamondTrap::whoAmI()
{
	std::cout << "🤔 Who am I?\n";
	std::cout << "🔹 DiamondTrap name: " << _name << "\n";
	std::cout << "🔸 ClapTrap name:   " << ClapTrap::getName() << "\n";
}
