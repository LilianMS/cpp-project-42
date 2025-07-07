#include "ScavTrap.hpp"
#include "colors.hpp"

int main() {
	std::cout << CYAN << BOLD << "\n🔐 Creating ScavTrap...\n" << RESET;
	ScavTrap st("GateKeeper");

	std::cout << YELLOW << "\n⚔️ ScavTrap attacks:\n" << RESET;
	st.attack("Intruder");

	std::cout << RED << "\n😵 ScavTrap takes damage:\n" << RESET;
	st.takeDamage(20);

	std::cout << GREEN << "\n🔧 ScavTrap repairs itself:\n" << RESET;
	st.beRepaired(15);

	std::cout << BLUE << "\n🚪 Guardian mode:\n" << RESET;
	st.guardGate();

	std::cout << MAGENTA << "\n🪫 Attacks until energy runs out:\n" << RESET;
	for (int i = 0; i < 51; ++i)
		st.attack("Intruder");

	std::cout << CYAN << BOLD << "\n🏁 End of ex01 test\n" << RESET;
	return 0;
}
