#include "main.hpp"

int main()
{
	std::cout << YELLOW << "\n🔬 Iniciando teste de estresse...\n"
			  << RESET;

	IMateriaSource *biblioteca = new MateriaSource();
	biblioteca->learnMateria(new Ice());
	biblioteca->learnMateria(new Cure());

	ICharacter *player = new Character("🧪 StressBot");
	ICharacter *dummy = new Character("🧍‍♂️ Dummy");

	const int totalCasts = MAX;
	const int unequipEvery = 2;

	for (int i = 0; i < totalCasts; ++i)
	{
		// Alterna entre ice e cure
		std::string tipo = (i % 2 == 0) ? "ice" : "cure";
		AMateria *m = biblioteca->createMateria(tipo);
		player->equip(m);

		// Usa magia no dummy
		int slot = i % 4;
		player->use(slot, *dummy);

		// De tempos em tempos faz unequip
		if (i % unequipEvery == 0)
		{
			int idx = std::rand() % 4;
			player->unequip(idx);
		}
	}

	std::cout << GREEN << "\n🧹 Encerrando e limpando recursos...\n"
			  << RESET;

	delete dummy;
	delete player;
	delete biblioteca;

	std::cout << BLUE << "\n✅ Teste de estresse finalizado com sucesso!\n"
			  << RESET;
	return 0;
}
