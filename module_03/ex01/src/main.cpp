#include "ScavTrap.hpp"
#include "constants.hpp"

int main()
{
	std::cout << CYAN << BOLD << "\n🔐 Creating ScavTrap...\n"
			  << RESET << std::endl;
	ScavTrap st("GateKeeper");

	std::cout << YELLOW << "\n⚔️ ScavTrap attacks:\n"
			  << RESET << std::endl;
	st.attack("Intruder");

	std::cout << RED << "\n😵 ScavTrap takes damage:\n"
			  << RESET << std::endl;
	st.takeDamage(20);

	std::cout << GREEN << "\n🔧 ScavTrap repairs itself:\n"
			  << RESET << std::endl;
	st.beRepaired(15);

	std::cout << BLUE << "\n🚪 Guardian mode:\n"
			  << RESET << std::endl;
	st.guardGate();

	std::cout << MAGENTA << "\n🪫 Attacks until energy runs out:\n"
			  << RESET << std::endl;
	for (int i = 0; i < 51; ++i)
		st.attack("Intruder");

	std::cout << CYAN << BOLD << "\n🏁 End of ex01 test\n"
			  << RESET << std::endl;
	return 0;
}
