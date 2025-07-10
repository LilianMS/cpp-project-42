#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name), _trashCount(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_TRASH; ++i)
		_trash[i] = NULL;
	std::cout << "🧍 Character \"" << _name << "\" constructed\n";
}

Character::Character(const Character &other) : _name(other._name), _trashCount(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	for (int i = 0; i < MAX_TRASH; ++i)
		_trash[i] = NULL;
	std::cout << "🧍 Character \"" << _name << "\" copy-constructed\n";
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
	std::cout << "🧍 Character \"" << _name << "\" assigned\n";
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

	std::cout << "🧍 Character \"" << _name << "\" destroyed\n";
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
					  << " in slot " << i << "\n";
			return;
		}
	}
	if (_trashCount < MAX_TRASH)
	{
		_trash[_trashCount++] = m;
		std::cout << "🗑️ " << _name << "'s inventory is full. Discarded "
				  << m->getType() << "\n";
	}
	else
	{
		std::cout << "💥 No space to store materia. Deleting " << m->getType() << "\n";
		delete m;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "⚠️ Nothing to unequip at slot " << idx << "\n";
		return;
	}

	if (_trashCount < MAX_TRASH)
	{
		AMateria *unequipped = _inventory[idx];
		_inventory[idx] = NULL;
		_trash[_trashCount++] = unequipped;
		std::cout << "🧍 " << _name << " unequipped " << unequipped->getType()
				  << " from slot " << idx << "\n";
	}
	else
	{
		std::cout << "💥 Lixeira cheia! Losing unequipped materia from slot "
				  << idx << "\n";
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "⚠️ Nothing to use at slot " << idx << "\n";
		return;
	}
	_inventory[idx]->use(target);
}
