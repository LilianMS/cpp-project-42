#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"  // Para acessar g_diamondValues

ScavTrap::ScavTrap()
: ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	
	// Salva valores na estrutura global para DiamondTrap
	g_diamondValues.scavTrapEP = getEnergyPoints();
}
ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "Creating ScavTrap: " << getName() << std::endl;
	
	// Salva valores na estrutura global para DiamondTrap
	g_diamondValues.scavTrapEP = getEnergyPoints();
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "Copying ScavTrap: " << getName() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroying ScavTrap: " << getName() << std::endl;
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
