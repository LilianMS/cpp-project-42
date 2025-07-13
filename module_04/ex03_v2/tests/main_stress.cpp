#include "main.hpp"

int main()
{
	std::cout << YELLOW << "\n🔬 Starting stress test...\n"
			  << RESET;

	IMateriaSource *biblioteca = new MateriaSource();
	biblioteca->learnMateria(new Ice());
	biblioteca->learnMateria(new Cure());

	ICharacter *player = new Character("🧪 StressBot");
	ICharacter *dummy = new Character("🧍 Dummy");

	const int totalCasts = 1000;
	const int unequipEvery = 7;

	AMateria *m;

	for (int i = 0; i < totalCasts; ++i)
	{
		std::string tipo = (i % 2 == 0) ? "ice" : "cure";
		m = biblioteca->createMateria(tipo);
		player->equip(m);

		int slot = i % 4;
		player->use(slot, *dummy);

		if (i % unequipEvery == 0)
		{
			int idx = std::rand() % 4;
			player->unequip(idx);
		}
	}

	std::cout << GREEN << "\n🧹 Shutting down and cleaning up resources...\n"
			  << RESET;

	delete dummy;
	delete player;
	delete biblioteca;

	std::cout << BLUE << "\n✅ Stress test finished successfully!\n"
			  << RESET;
	return (0);
}
