#include "DiamondTrap.hpp"
#include "colors.hpp"

int main() {
	std::cout << CYAN << BOLD << "\n✨ Creating DiamondTrap...\n" << RESET;
	DiamondTrap dia("💎 Diamantino");
	std::cout << "Initial values:\n";
	std::cout << "Name: " << dia.getName() << "\n";
	std::cout << "Hit Points: " << dia.getHitPoints() << "\n";
	std::cout << "Energy Points: " << dia.getEnergyPoints() << "\n";
	std::cout << "Attack Damage: " << dia.getAttackDamage() << "\n";
	
	std::cout << YELLOW << "\n⚔️ Special attack:\n" << RESET;
	dia.attack("Dangerous_Target");

	std::cout << GREEN << "\n🔧 Repairing:\n" << RESET;
	dia.beRepaired(25);

	std::cout << RED << "\n💥 Taking damage:\n" << RESET;
	dia.takeDamage(50);

std::cout << "\nUpdate values:\n";
	std::cout << "Name: " << dia.getName() << "\n";
	std::cout << "Hit Points: " << dia.getHitPoints() << "\n";
	std::cout << "Energy Points: " << dia.getEnergyPoints() << "\n";
	std::cout << "Attack Damage: " << dia.getAttackDamage() << "\n";

	std::cout << BLUE << "\n🙋‍♂️ Revealing identity:\n" << RESET;
	dia.whoAmI();

	std::cout << MAGENTA << "\n🧪 Test finished.\n" << RESET;
	return 0;
}
