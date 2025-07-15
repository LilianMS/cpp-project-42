#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include "constants.hpp"

int main()
{
	{
		std::cout << CYAN << BOLD << PERSON << " [Bob's Test]" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << GREEN << GUN << " ";
		bob.attack();
		std::cout << RESET;

		std::cout << YELLOW << CLUB << " Bob switches weapon!" << RESET << std::endl;
		club.setType("some other type of club");

		std::cout << GREEN << GUN << " ";
		bob.attack();
		std::cout << RESET;
	}

	std::cout << std::endl;

	{
		std::cout << CYAN << BOLD << PERSON << " [Jim's Test]" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		std::cout << RED << GUN << " ";
		jim.attack();
		std::cout << RESET;

		std::cout << YELLOW << CLUB << " Jim picks up a weapon!" << RESET << std::endl;
		jim.setWeapon(club);

		std::cout << GREEN << GUN << " ";
		jim.attack();
		std::cout << RESET;

		std::cout << YELLOW << CLUB << " Jim switches weapon!" << RESET << std::endl;
		club.setType("some other type of club");

		std::cout << GREEN << GUN << " ";
		jim.attack();
		std::cout << RESET;
	}

	return (0);
}
