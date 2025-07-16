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
	typedef void (Harl::*HarlMethod)();

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlMethod methods[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*methods[i])();
			return;
		}
	}
	std::cout << "[UNKNOWN] Invalid complaint level: " << level << std::endl;
}
