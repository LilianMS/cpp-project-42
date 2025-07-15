#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: AAnimal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "🐶 Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other)
	: AAnimal(other), _brain(new Brain(*other._brain))
{
	// _brain = new Brain(*other._brain); // deep copy
	_type = other._type;
	std::cout << "🐶 Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "🐶 Dog copy-assigned" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain); // deep copy
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "🐶 Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (_brain);
}
