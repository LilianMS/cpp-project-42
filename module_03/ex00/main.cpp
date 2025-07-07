#include "ClapTrap.hpp"
#include "colors.hpp"

int main() {
	std::cout << CYAN << BOLD << "\n🤖 Creating ClapTraps...\n" << RESET;
	ClapTrap robotA("Alpha");
	ClapTrap robotB("Beta");

	std::cout << YELLOW << "\n🚀 Alpha attacks Beta:\n" << RESET;
	robotA.attack("Beta");

	std::cout << RED << "\n💥 Beta takes damage:\n" << RESET;
	robotB.takeDamage(3);

	std::cout << GREEN << "\n🔧 Beta repairs itself:\n" << RESET;
	robotB.beRepaired(2);

	std::cout << MAGENTA << "\n⚡ Draining all energy from Alpha:\n" << RESET;
	for (int i = 0; i < 11; ++i)
		robotA.attack("Beta");

	std::cout << BLUE << "\n🛑 Alpha tries to repair with no energy:\n" << RESET;
	robotA.beRepaired(5);

	std::cout << RED << "\n☠️ Beta receives fatal damage:\n" << RESET;
	robotB.takeDamage(100);

	std::cout << YELLOW << "\n🪦 Beta tries to attack after dying:\n" << RESET;
	robotB.attack("Alpha");

	std::cout << CYAN << BOLD << "\n🏁 End of ex00 test\n" << RESET;
	return 0;
}
