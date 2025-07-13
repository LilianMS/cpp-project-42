#include "Animal.hpp"
#include <iostream>

Animal::Animal()
	: _type("Animal")
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal &other)
	: _type(other._type)
{
	std::cout << "Animal copy-constructed" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy-assigned" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "Grrr..." << std::endl;
}
