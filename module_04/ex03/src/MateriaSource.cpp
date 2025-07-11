#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_slots[i] = NULL;
	std::cout << "🏭 MateriaSource constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
		_slots[i] = other._slots[i] ? other._slots[i]->clone() : NULL;
	std::cout << "🏭 MateriaSource copy-constructed" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_slots[i])
			{
				delete _slots[i];
				_slots[i] = NULL;
			}
			if (other._slots[i])
				_slots[i] = other._slots[i]->clone();
		}
	}
	std::cout << "🏭 MateriaSource assigned" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete _slots[i];
	std::cout << "🏭 MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			std::cout << "🏭 Learned materia: " << m->getType() << " (slot " << i << ")" << std::endl;
			return ;
		}
	}
	std::cout << "⚠️  MateriaSource full. Cannot learn more." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_slots[i] && _slots[i]->getType() == type)
		{
			std::cout << "🏭 Creating materia of type: " << type << std::endl;
			return (_slots[i]->clone());
		}
	}
	std::cout << "⚠️  Materia not found: " << type << std::endl;
	return (NULL);
}
