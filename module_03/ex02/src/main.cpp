#include "FragTrap.hpp"
#include "constants.hpp"

int main()
{
	std::cout << CYAN << "✨ Creating FragTrap ✨" << RESET << std::endl;
	FragTrap frag("Fragger");

	std::cout << YELLOW << "\n🔫 Attack started:" << RESET << std::endl;
	frag.attack("🎯 Target");

	std::cout << RED << "\n💢 Fragger takes damage:" << RESET << std::endl;
	frag.takeDamage(40);

	std::cout << GREEN << "\n🔧 Fragger repairs itself:" << RESET << std::endl;
	frag.beRepaired(25);

	std::cout << BLUE << "\n🙌 Requesting high five:" << RESET << std::endl;
	frag.highFivesGuys();

	std::cout << MAGENTA << "\n🧹 Ending program..." << RESET << std::endl;

	return (0);
}
