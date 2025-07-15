#include "ClapTrap.hpp"
#include "constants.hpp"

int main()
{
	std::cout << CYAN << BOLD << "\n🤖 Creating ClapTraps...\n"
			  << RESET << std::endl;
	ClapTrap robotA("Alpha");
	ClapTrap robotB("Beta");

	std::cout << YELLOW << "\n🚀 Alpha attacks Beta:\n"
			  << RESET << std::endl;
	robotA.attack("Beta");

	std::cout << RED << "\n💥 Beta takes damage:\n"
			  << RESET << std::endl;
	robotB.takeDamage(3);

	std::cout << GREEN << "\n🔧 Beta repairs itself:\n"
			  << RESET << std::endl;
	robotB.beRepaired(2);

	std::cout << MAGENTA << "\n⚡ Draining all energy from Alpha:\n"
			  << RESET << std::endl;
	for (int i = 0; i < 11; ++i)
		robotA.attack("Beta");

	std::cout << BLUE << "\n🛑 Alpha tries to repair with no energy:\n"
			  << RESET << std::endl;
	robotA.beRepaired(5);

	std::cout << RED << "\n☠️ Beta receives fatal damage:\n"
			  << RESET << std::endl;
	robotB.takeDamage(100);

	std::cout << YELLOW << "\n🪦 Beta tries to attack after dying:\n"
			  << RESET << std::endl;
	robotB.attack("Alpha");

	std::cout << CYAN << BOLD << "\n🏁 End of ex00 test\n"
			  << RESET << std::endl;
	return 0;
}
