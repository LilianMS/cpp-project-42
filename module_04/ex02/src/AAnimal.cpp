#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
	: _type("AAnimal")
{
	std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
	: _type(other._type)
{
	std::cout << "AAnimal copy-constructed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy-assigned" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}

std::string AAnimal::getType() const
{
	return (_type);
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "Grrr..." << std::endl;
// }
