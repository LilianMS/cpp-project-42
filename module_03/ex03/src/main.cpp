#include "DiamondTrap.hpp"
#include "constants.hpp"

int main()
{
	std::cout << CYAN << "✨ Creating DiamondTrap..." << RESET << std::endl;

	DiamondTrap dia("💎 Diamantino");

	std::cout << BOLD << "\n--- Initial values ---" RESET << std::endl;
	std::cout << "Name: " << dia.getName() << std::endl;
	std::cout << "Hit Points: " << dia.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << dia.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << dia.getAttackDamage() << std::endl;
	std::cout << "---------------------\n" << std::endl;

	std::cout << YELLOW << "⚔️  Special attack:"  << RESET << std::endl;
	dia.attack("Dangerous_Target");

	std::cout << RED << "💥 Taking damage:"  << RESET << std::endl;
	dia.takeDamage(50);

	std::cout << GREEN << "🔧 Repairing:"  << RESET << std::endl;
	dia.beRepaired(25);

	std::cout << YELLOW << "🛡️  ScavTrap actions:" << RESET << std::endl;
	dia.guardGate();


	std::cout << ORANGE << "🤚 FragTrap actions:"  << RESET << std::endl;
	dia.highFivesGuys();

	std::cout << std::endl
			  << BOLD << "--- Update values ---" << RESET << std::endl;
	std::cout << "Name: " << dia.getName() << std::endl;
	std::cout << "Hit Points: " << dia.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << dia.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << dia.getAttackDamage() << std::endl;
	std::cout << "---------------------\n" << std::endl;

	std::cout << BLUE << "🙋‍♂️ Revealing identity:\n" << RESET << std::endl;
	dia.whoAmI();

	std::cout << MAGENTA << "\n🧪 Test finished." << RESET << std::endl;

	return (0);
}
