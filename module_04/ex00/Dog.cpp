#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal()
{
	_type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other)
	: Animal(other)
{
	std::cout << "Dog copy-constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy-assigned" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
