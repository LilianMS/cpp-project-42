#include "DiamondTrap.hpp"
#include "colors.hpp"

int main() {
	std::cout << CYAN << "\n✨ Creating DiamondTrap ✨\n" << RESET;
	DiamondTrap diamond("💎 Sparky");

	std::cout << YELLOW << "\n💎 Who am I?\n" << RESET;
	diamond.whoAmI();

	std::cout << YELLOW << "\n💎 DiamondTrap attack (using ScavTrap::attack):\n" << RESET;
	diamond.attack("🎯 Enemy");

	std::cout << RED << "\n💢 DiamondTrap takes damage:\n" << RESET;
	diamond.takeDamage(50);

	std::cout << GREEN << "\n🔧 DiamondTrap repairs itself:\n" << RESET;
	diamond.beRepaired(30);

	std::cout << BLUE << "\n💎 Guardian Mode (inherited from ScavTrap):\n" << RESET;
	diamond.guardGate();

	std::cout << PURPLE << "\n🙌 High Five (inherited from FragTrap):\n" << RESET;
	diamond.highFivesGuys();

	std::cout << CYAN << "\n🔍 Checking identity again:\n" << RESET;
	diamond.whoAmI();

	std::cout << MAGENTA << "\n🧹 Ending program...\n" << RESET;
	
	return (0);
}
