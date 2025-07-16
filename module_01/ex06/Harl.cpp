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
			break;
		}
	}

	switch (index)
	{
	case 0:
		goto debug_label;
	case 1:
		goto info_label;
	case 2:
		goto warning_label;
	case 3:
		goto error_label;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	debug_label:
		debug();
	info_label:
		info();
	warning_label:
		warning();
	error_label:
		error();
}
