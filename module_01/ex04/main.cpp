#include "Replace.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	Replace replacer(argv[1], argv[2], argv[3]);

	if (!replacer.process())
		return (1);

	return (0);
}
