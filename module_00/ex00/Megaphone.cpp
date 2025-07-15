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

void Megaphone::noArg() const
{
	std::cout << "📣 ";
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void Megaphone::toUpperCase(std::string &str) const
{
	std::string result;
	for (size_t i = 0; i < str.length();)
	{
		if ((unsigned char)str[i] >= 0xC3 && i + 1 < str.length())
		{
			if ((unsigned char)str[i] == 0xC3)
			{
				unsigned char next = (unsigned char)str[i + 1];
				switch (next)
				{
					case 0xA1: result += "\xC3\x81"; i += 2; continue;
					case 0xA9: result += "\xC3\x89"; i += 2; continue;
					case 0xAD: result += "\xC3\x8D"; i += 2; continue;
					case 0xB3: result += "\xC3\x93"; i += 2; continue;
					case 0xBA: result += "\xC3\x9A"; i += 2; continue;
					case 0xA3: result += "\xC3\x83"; i += 2; continue;
					case 0xB5: result += "\xC3\x95"; i += 2; continue;
					case 0xA2: result += "\xC3\x82"; i += 2; continue;
					case 0xAA: result += "\xC3\x8A"; i += 2; continue;
					case 0xB4: result += "\xC3\x94"; i += 2; continue;
					case 0xA0: result += "\xC3\x80"; i += 2; continue;
					case 0xA7: result += "\xC3\x87"; i += 2; continue;
					case 0xB1: result += "\xC3\x91"; i += 2; continue;
					case 0xBC: result += "\xC3\x9C"; i += 2; continue;
					case 0xAF: result += "\xC3\x8F"; i += 2; continue;
					case 0xAB: result += "\xC3\x8B"; i += 2; continue;
					case 0xA4: result += "\xC3\x84"; i += 2; continue;
				}
			}
		}
		result += std::toupper(static_cast<unsigned char>(str[i]));
		++i;
	}
	str = result;
}

/*
 * Manual UTF-8 Character Conversion Explanation:
 * 
 * This implementation manually converts accented lowercase letters to uppercase
 * because of the constraints and limitations of C++98:
 * 
 * 1. C++98 Limitations:
 *    - Limited locale support and UTF-8 handling
 *    - std::toupper() doesn't work properly with multi-byte UTF-8 characters
 *    - No modern Unicode libraries available
 * 
 * 2. Project Constraints:
 *    - Cannot use containers (vector, map, etc.)
 *    - Cannot use <algorithm> header
 *    - Must be compatible with C++98 standard
 * 
 * 3. UTF-8 Encoding:
 *    - Accented characters are encoded as 2-byte sequences
 *    - First byte: 0xC3 (for most Latin accented characters)
 *    - Second byte: determines the specific character
 * 
 * 4. Manual Mapping:
 *    - Each case maps the lowercase UTF-8 sequence to uppercase
 *    - Example: á (0xC3 0xA1) → Á (0xC3 0x81)
 *    - Covers Portuguese, Spanish, French, German, and some English words
 * 
 * This approach ensures proper handling of accented characters while
 * maintaining compatibility with C++98 and project requirements.
 * 
 * Examples:
 *
 *	0xA1 -> \xC3\x81 == á -> Á
 *	0xA9 -> \xC3\x89 == é -> É
 *	0xAD -> \xC3\x8D == í -> Í
 *	0xB3 -> \xC3\x93 == ó -> Ó
 *	0xBA -> \xC3\x9A == ú -> Ú
 *	0xA3 -> \xC3\x83 == ã -> Ã
 *	0xB5 -> \xC3\x95 == õ -> Õ
 *	0xA2 -> \xC3\x82 == â -> Â
 *	0xAA -> \xC3\x8A == ê -> Ê
 *	0xB4 -> \xC3\x94 == ô -> Ô
 *	0xA0 -> \xC3\x80 == à -> À
 *	0xA7 -> \xC3\x87 == ç -> Ç
 *	0xB1 -> \xC3\x91 == ñ -> Ñ
 *	0xBC -> \xC3\x9C == ü -> Ü
 *	0xAF -> \xC3\x8F == ï -> Ï
 *	0xAB -> \xC3\x8B == ë -> Ë
 *	0xA4 -> \xC3\x84 == ä -> Ä
 *
*/