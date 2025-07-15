
#include "TrashCan.hpp"
#include <iostream>

TrashCan::TrashCan() : _count(0)
{
	for (int i = 0; i < MAX_TRASH; ++i)
		_items[i] = NULL;
}

TrashCan::~TrashCan()
{
	clear();
}

TrashCan::TrashCan(const TrashCan &other) : _count(0)
{
	for (int i = 0; i < other._count; ++i)
		_items[i] = other._items[i]->clone();
	_count = other._count;
}

TrashCan &TrashCan::operator=(const TrashCan &other)
{
	if (this != &other)
	{
		clear();
		for (int i = 0; i < other._count; ++i)
			_items[i] = other._items[i]->clone();
		_count = other._count;
	}
	return (*this);
}

bool TrashCan::store(AMateria *m)
{
	if (!m)
		return (false);
	if (_count >= MAX_TRASH)
		clear();
	_items[_count++] = m;
	std::cout << "🗑️  Stored in trash: " << m->getType() << "\n";
	return (true);
}

void TrashCan::clear()
{
	for (int i = 0; i < _count; ++i)
	{
		delete _items[i];
		_items[i] = NULL;
	}
	_count = 0;
}
