#include "main.hpp"

void printStep(std::string msg)
{
	std::cout << BLUE << "\n🔹 " << msg << RESET << std::endl;
}

int main()
{
	std::cout << YELLOW << "\n✨ Welcome to MateriaCraft - cpp04/ex03\n"
			  << RESET;
	std::cout << CYAN << "🎓 Exploring Interfaces, Inheritance and Polymorphism!\n"
			  << RESET;

	// Interface IMateriaSource
	printStep("Interface 📚 IMateriaSource defines the magic factory.");
	IMateriaSource *library = new MateriaSource();
	library->learnMateria(new Ice());
	library->learnMateria(new Cure());
	library->learnMateria(new Tnt()); // Adds TNT to the library

	// Interface ICharacter
	printStep("Interface 🧙 ICharacter defines magical characters.");
	ICharacter *steve = new Character("🎮 Steve");
	ICharacter *enemy = new Character("👾 Creeper");

	printStep("Factory creates magics by cloning models:");
	AMateria *ice = library->createMateria("ice");
	AMateria *cure = library->createMateria("cure");
	AMateria *tnt = library->createMateria("tnt"); // Creates TNT

	printStep("Character equips magics:");
	steve->equip(ice);	// 0
	steve->equip(cure); // 1
	steve->equip(tnt);	// 2

	steve->equip(library->createMateria("fire")); // Steve tries to equip a non-existent magic

	steve->equip(NULL); // Steve tries to equip a null

	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT
	steve->equip(tnt->clone()); // 3 Steve equips another TNT

	printStep("Magics are used via pointers and polymorphism:");
	steve->use(0, *enemy); // ice
	steve->use(1, *enemy); // cure
	steve->use(2, *enemy);
	steve->use(3, *enemy);
	steve->use(4, *enemy);

	printStep("Unequipping magics:");
	steve->unequip(0); // Unequips the magic from slot 0 (ice)
	steve->unequip(1); // Unequips the magic from slot 1 (cure)
	steve->unequip(2); // Unequips the magic from slot 2 (TNT)
	steve->unequip(3); // Unequips the magic from slot 3 (TNT)

	printStep("Dismantling scenario with delete and destructors:");
	delete enemy;
	delete steve;
	delete library;

	std::cout << GREEN << "\n✅ End of presentation. No leaks if all went well!\n"
			  << RESET;
	return 0;
}