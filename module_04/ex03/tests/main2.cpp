#include "main.hpp"

int main()
{
	std::cout << BLUE << "\n✨ Welcome to the world of MateriaCraft! ✨\n"
			  << RESET;

	IMateriaSource *library = new MateriaSource();
	std::cout << GREEN << "\n📘 The arcane Library has learned two spells:" << RESET << std::endl;
	library->learnMateria(new Ice());
	library->learnMateria(new Cure());

	std::cout << GREEN << "❄️ Ice and 💧 Cure are ready to be cast!\n"
			  << RESET;

	ICharacter *player = new Character("🎮 Steve");
	std::cout << GREEN << "\n🧍 Character created: " << player->getName() << RESET << "\n";

	AMateria *spell;

	spell = library->createMateria("ice");
	player->equip(spell);
	spell = library->createMateria("cure");
	player->equip(spell);

	ICharacter *enemy = new Character("👾 Creeper");

	std::cout << YELLOW << "\n⚔️  " << player->getName() << " faces " << enemy->getName() << "!" << RESET << "\n";

	player->use(0, *enemy); // Ice
	player->use(1, *enemy); // Cure (ironically 😅)

	std::cout << CYAN << "\n🎒 Testing full slots and unequip:" << RESET << std::endl;
	AMateria *extra = library->createMateria("ice");
	player->equip(extra); // slot 2
	AMateria *extra2 = library->createMateria("cure");
	player->equip(extra2); // slot 3
	AMateria *overflow = library->createMateria("ice");
	player->equip(overflow); // inventory full

	player->unequip(2); // freeing slot

	std::cout << RED << "\n🧨 End of the adventure!\n"
			  << RESET;

	delete enemy;
	delete player;
	delete library;

	std::cout << GREEN << "✅ All materias and characters were correctly destroyed.\n"
			  << RESET;
	return 0;
}
