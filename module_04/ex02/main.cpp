#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "colors.hpp"

int main()
{
	// const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << BLUE << "🐶 " << j->getType() << " says " << RESET;
	j->makeSound();
	std::cout << MAGENTA << "🐱 " << i->getType() << " says " << RESET;
	i->makeSound();
	// std::cout << ORANGE << "🐾 " << meta->getType() << " says " << RESET;
	// meta->makeSound();

	// delete meta;
	delete j;
	delete i;

	std::cout << std::endl 
			  << CYAN << "🔹 Testing deep copy with Dog:" << RESET << std::endl;

	Dog basic;
	basic.getBrain()->setIdea(0, "Protect the house");

	std::cout << YELLOW << "Setting idea[0] of basic dog to: " 
			  << GREEN << "\"Protect the house\"" << RESET << std::endl;

	Dog copy = basic;
	copy.getBrain()->setIdea(0, "Run in the park");

	std::cout << YELLOW << "Setting idea[0] of copy dog to: " 
			  << GREEN << "\"Run in the park\"" << RESET << std::endl;

	std::cout << BOLD << "Basic dog idea[0]: " << RESET 
			  << BLUE << basic.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << BOLD << "Copy dog idea[0]:  " << RESET 
			  << MAGENTA << copy.getBrain()->getIdea(0) << RESET << std::endl;

	return (0);
}
