#include "main.hpp"

int main()
{
	std::cout << BLUE << "\n✨ Bem-vindo ao mundo do MateriaCraft! ✨\n"
			  << RESET;

	IMateriaSource *biblioteca = new MateriaSource();
	std::cout << GREEN << "\n📘 A Biblioteca arcana aprendeu duas magias:" << RESET << std::endl;
	biblioteca->learnMateria(new Ice());
	biblioteca->learnMateria(new Cure());

	ICharacter *player = new Character("🎮 Steve");
	std::cout << GREEN << "\n🧍 Personagem criado: " << player->getName() << RESET << "\n";

	AMateria *magia;

	magia = biblioteca->createMateria("ice");
	player->equip(magia);
	magia = biblioteca->createMateria("cure");
	player->equip(magia);

	ICharacter *inimigo = new Character("👾 Creeper");

	std::cout << YELLOW << "\n⚔️  " << player->getName() << " enfrenta " << inimigo->getName() << "!" << RESET << "\n";

	player->use(0, *inimigo); // Ice
	player->use(1, *inimigo); // Cure (ironicamente 😅)

	std::cout << CYAN << "\n🎒 Testando slots cheios e unequip:" << RESET << std::endl;
	AMateria *extra = biblioteca->createMateria("ice");
	player->equip(extra); // slot 2
	AMateria *extra2 = biblioteca->createMateria("cure");
	player->equip(extra2); // slot 3
	AMateria *overflow = biblioteca->createMateria("ice");
	player->equip(overflow); // inventário cheio

	player->unequip(2); // liberando slot

	std::cout << RED << "\n🧨 Fim da aventura!\n"
			  << RESET;

	delete inimigo;
	delete player;
	delete biblioteca;

	std::cout << GREEN << "✅ Todas as matérias e personagens foram corretamente destruídos.\n"
			  << RESET;
	return 0;
}
