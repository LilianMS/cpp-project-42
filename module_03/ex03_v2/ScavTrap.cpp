#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}
ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "ScavTrap named constructor called for " << getName() << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << getName() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() == 0 || getHitPoints() == 0) {
		std::cout << "ScavTrap " << getName()
				<< " has no energy or is dead and can't attack." << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName()
			<< " attacks " << target
			<< ", causing " << getAttackDamage()
			<< " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (getHitPoints() == 0) {
		std::cout << "ScavTrap " << getName()
				<< " is dead and can't enter guard mode." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName()
			<< " is now in guard mode." << std::endl;
}

unsigned int ScavTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

void ScavTrap::setEnergyPoints(unsigned int ep)
{
	_energyPoints = ep;
}