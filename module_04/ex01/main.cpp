#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "colors.hpp"

int main()
{
	std::cout << BLUE "🔹 Creating an array of Animal* with Dog and Cat:" RESET << std::endl;
	const int size = 4;
	Animal *animals[size];

	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << CYAN "\n🔸 Testing polymorphic sounds:" RESET << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << YELLOW << "[" << i << "] " << RESET;
		animals[i]->makeSound();
	}

	std::cout << MAGENTA "\n🔸 Destroying all animals:" RESET << std::endl;
	for (int i = 0; i < size; ++i)
	{
		delete animals[i];
	}

	std::cout << GREEN "\n🔹 Testing deep copy with Cat:" RESET << std::endl;
	Cat original;
	original.getBrain()->setIdea(0, "Sleep");
	original.getBrain()->setIdea(1, "Eat");

	Cat copy = original;

	std::cout << "Original idea[0]: " << YELLOW << original.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << "Copy idea[0]:     " << YELLOW << copy.getBrain()->getIdea(0) << RESET << std::endl;

	std::cout << RED "\n🔸 Changing idea of the copy:" RESET << std::endl;
	copy.getBrain()->setIdea(0, "Hunt");

	std::cout << "Original idea[0]: " << YELLOW << original.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << "Copy idea[0]:     " << YELLOW << copy.getBrain()->getIdea(0) << RESET << std::endl;

	return (0);
}
