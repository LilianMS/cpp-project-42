#include "Megaphone.hpp"

Megaphone::Megaphone() {}
Megaphone::~Megaphone() {}

void Megaphone::project(int argc, char **argv) const
{
	if (argc < 2)
	{
		noArg();
		return;
	}
	std::cout << "📣 ";
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		toUpperCase(str);
		std::cout << str;
		if (i < argc - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void Megaphone::toUpperCase(std::string &str) const
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	}
}

void Megaphone::noArg() const
{
	std::cout << "📣 ";
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
