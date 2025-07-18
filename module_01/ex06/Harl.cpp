#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon on my burger!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] Adding bacon costs more money." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve some free bacon." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager!" << std::endl;
}

void Harl::complain(std::string level)
{
	int index = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			index = i;
			break ;
		}
	}

	switch (index)
	{
	case 0:
		debug();
		// fallthrough
	case 1:
		info();
		// fallthrough
	case 2:
		warning();
		// fallthrough
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}