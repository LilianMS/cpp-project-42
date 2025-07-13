#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name), _trashCount(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_TRASH; ++i)
		_trash[i] = NULL;
	std::cout << "🧍 Character \"" << _name << "\" constructed" << std::endl;
}

Character::Character(const Character &other) : _name(other._name), _trashCount(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	for (int i = 0; i < MAX_TRASH; ++i)
		_trash[i] = NULL;
	std::cout << "🧍 Character \"" << _name << "\" copy-constructed" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;

		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
		}

		for (int i = 0; i < _trashCount; ++i)
		{
			delete _trash[i];
			_trash[i] = NULL;
		}
		_trashCount = 0;
	}
	std::cout << "🧍 Character \"" << _name << "\" assigned" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}

	for (int i = 0; i < _trashCount; ++i)
	{
		delete _trash[i];
		_trash[i] = NULL;
	}

	std::cout << "🧍 Character \"" << _name << "\" destroyed" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "🧍 " << _name << " equips " << m->getType()
					  << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "🗑️ " << _name << "'s inventory is full. Discarded "
			  << m->getType() << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "⚠️  Nothing to unequip at slot " << idx << std::endl;
		return;
	}
	std::string unequipped = _inventory[idx]->getType();
	std::cout << "-------teste nome de " << _name << " unequipped " << unequipped << " from slot " << idx << std::endl;
	if (_trashCount >= MAX_TRASH)
	{
		_discardOne();
		_trash[_trashCount++] = _inventory[idx];
	}
	else
	{
		_trash[_trashCount++] = _inventory[idx];
	}
	_inventory[idx] = NULL;
	std::cout << std::endl << "🧍 " << _name << " unequipped " << unequipped
			  << " from slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "⚠️  Nothing to use at slot " << idx << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}

void Character::_discardOne()
{
	if (_trashCount == 0)
		return;

	delete _trash[0];

	for (int i = 1; i < _trashCount; ++i)
		_trash[i - 1] = _trash[i];

	_trash[--_trashCount] = NULL;
}
