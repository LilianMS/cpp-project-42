#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <csignal>

void handleSigint(int signum)
{
	(void)signum;
	std::cout << "\n🛑 Program interrupted with Ctrl+C. Goodbye!" << std::endl;
	std::exit(0);
}

int main()
{
	std::signal(SIGINT, handleSigint);

	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "\n 📞 Welcome to My Awesome PhoneBook!\n" << std::endl;
	while (true)
	{
		std::cout << " [MyPhoneBook] > Enter command (ADD, SEARCH, EXIT): ";

		if (!std::getline(std::cin, command))
		{
			std::cout << "\n > [!] EOF received. Exiting program [!]" << std::endl;
			break ;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << " > [!] Unknown command [!]\n";
	}
	std::cout << " [MyPhoneBook] > 👋 Bye!\n";
	return (0);
}
