#include "FragTrap.hpp"
#include "colors.hpp"


int main() {
	std::cout << CYAN << "\n✨ Criando FragTrap ✨\n" << RESET;
	FragTrap frag("💥 Fragger");

	std::cout << YELLOW << "\n🔫 Ataque iniciado:\n" << RESET;
	frag.attack("🎯 Alvo");

	std::cout << RED << "\n💢 Fragger sofre dano:\n" << RESET;
	frag.takeDamage(40);

	std::cout << GREEN << "\n🔧 Fragger se repara:\n" << RESET;
	frag.beRepaired(25);

	std::cout << BLUE << "\n🙌 Solicitando high five:\n" << RESET;
	frag.highFivesGuys();

	std::cout << MAGENTA << "\n🧹 Finalizando programa...\n" << RESET;
	
	return (0);
}
