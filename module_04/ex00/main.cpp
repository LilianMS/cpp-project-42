#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "colors.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << BLUE << "🐶 " << j->getType() << " says " << RESET;
	j->makeSound();
	std::cout << MAGENTA << "🐱 " << i->getType() << " says " << RESET;
	i->makeSound();
	std::cout << ORANGE << "🐾 " << meta->getType() << " says " << RESET;
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << YELLOW << "\n-- WrongAnimals --\n"
			  << RESET;

	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();

	std::cout << RED << "🙀 " << wc->getType() << " says " << RESET;
	wc->makeSound();
	
	delete wa;
	delete wc;

	return (0);
}
