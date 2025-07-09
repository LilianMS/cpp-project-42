#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap named constructor called for " << _name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other._name)
, _hitPoints(other._hitPoints)
, _energyPoints(other._energyPoints)
, _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << _name << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other) {
		_name         = other._name;
		_hitPoints    = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << "\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ClapTrap " << _name
				<< " has no energy or is dead and can't attack.\n";
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name
			<< " attacks " << target
			<< ", causing " << _attackDamage
			<< " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead.\n";
		return ;
	}
	_hitPoints = (amount >= _hitPoints ? 0 : _hitPoints - amount);
	std::cout << "ClapTrap " << _name
			<< " takes " << amount
			<< " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't be repaired.\n";
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
			<< " repairs itself for " << amount
			<< " hit points!\n";
}

// ——————————————————————————————————————————————————————————————
// getters:

const std::string& ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

// ——————————————————————————————————————————————————————————————
// setters:

void ClapTrap::setName(const std::string& name)
{
	_name = name;
}
void ClapTrap::setHitPoints(unsigned int hp)
{
	_hitPoints = hp;
}
void ClapTrap::setEnergyPoints(unsigned int ep)
{
	_energyPoints = ep;
}
void ClapTrap::setAttackDamage(unsigned int ad)
{
	_attackDamage = ad;
}
// ——————————————————————————————————————————————————————————————
// end of getters and setters