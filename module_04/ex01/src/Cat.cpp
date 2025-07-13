#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << "🐱 Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other)
	: Animal(other), _brain(new Brain(*other._brain))
{
	// _brain = new Brain(*other._brain);  // deep copy
	_type = other._type;
	std::cout << "🐱 Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "🐱 Cat copy-assigned" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain); // deep copy
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "🐱 Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (_brain);
}
