#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "🧠 Brain default constructor called\n";
	for (int i = 0; i < 100; ++i)
		_ideas[i] = "";
}

Brain::Brain(const Brain &other)
{
	std::cout << "🧠 Brain copy constructor called\n";
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "🧠 Brain assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "🧠 Brain destructor called\n";
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (_ideas[index]);
	return ("");
}
