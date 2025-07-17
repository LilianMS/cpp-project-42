#include <iostream>
#include <string>
#include "constants.hpp"

void printHeader(const std::string &title)
{
	std::cout << BOLD << CYAN << "=" << std::string(50, '=') << RESET << std::endl;
	std::cout << BOLD << CYAN << "  " << title << RESET << std::endl;
	std::cout << BOLD << CYAN << "=" << std::string(50, '=') << RESET << std::endl;
}

void printSubHeader(const std::string &subtitle)
{
	std::cout << BOLD << YELLOW << "\n🔍 " << subtitle << RESET << std::endl;
}

int main()
{
	printHeader("🧠 POINTERS AND REFERENCES DEMONSTRATION");

	// ============ BASIC TEST ============
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	printSubHeader("Basic Test - Addresses");
	std::cout << GREEN << "brain      : " << RESET << &brain << std::endl;
	std::cout << BLUE << "stringPTR  : " << RESET << stringPTR << std::endl;
	std::cout << MAGENTA << "stringREF  : " << RESET << &stringREF << std::endl;

	printSubHeader("Basic Test - Contents");
	std::cout << GREEN << "brain      : " << RESET << "\"" << brain << "\"" << std::endl;
	std::cout << BLUE << "stringPTR  : " << RESET << "\"" << *stringPTR << "\"" << std::endl;
	std::cout << MAGENTA << "stringREF  : " << RESET << "\"" << stringREF << "\"" << std::endl;

	// ============ MODIFICATIONS ============
	printSubHeader("🔄 Modifying through pointer");
	*stringPTR = "MODIFIED BY POINTER";
	std::cout << GREEN << "brain      : " << RESET << "\"" << brain << "\"" << std::endl;
	std::cout << BLUE << "stringPTR  : " << RESET << "\"" << *stringPTR << "\"" << std::endl;
	std::cout << MAGENTA << "stringREF  : " << RESET << "\"" << stringREF << "\"" << std::endl;

	printSubHeader("🔄 Modifying through reference");
	stringREF = "MODIFIED BY REFERENCE";
	std::cout << GREEN << "brain      : " << RESET << "\"" << brain << "\"" << std::endl;
	std::cout << BLUE << "stringPTR  : " << RESET << "\"" << *stringPTR << "\"" << std::endl;
	std::cout << MAGENTA << "stringREF  : " << RESET << "\"" << stringREF << "\"" << std::endl;

	// ============ COMPARISONS ============
	printSubHeader("⚖️ Comparisons");
	std::cout << WHITE << "brain == *stringPTR : " << RESET << (brain == *stringPTR ? GREEN "✅ true" : RED "❌ false") << RESET << std::endl;
	std::cout << WHITE << "brain == stringREF  : " << RESET << (brain == stringREF ? GREEN "✅ true" : RED "❌ false") << RESET << std::endl;
	std::cout << WHITE << "&brain == stringPTR : " << RESET << (&brain == stringPTR ? GREEN "✅ true" : RED "❌ false") << RESET << std::endl;
	std::cout << WHITE << "&brain == &stringREF: " << RESET << (&brain == &stringREF ? GREEN "✅ true" : RED "❌ false") << RESET << std::endl;

	// ============ MULTIPLE POINTERS ============
	printSubHeader("🔗 Multiple pointers to the same variable");
	std::string *anotherPTR = &brain;
	std::string *yetAnotherPTR = stringPTR;

	std::cout << GREEN << "brain         : " << RESET << &brain << " → \"" << brain << "\"" << std::endl;
	std::cout << BLUE << "stringPTR     : " << RESET << stringPTR << " → \"" << *stringPTR << "\"" << std::endl;
	std::cout << YELLOW << "anotherPTR    : " << RESET << anotherPTR << " → \"" << *anotherPTR << "\"" << std::endl;
	std::cout << MAGENTA << "yetAnotherPTR : " << RESET << yetAnotherPTR << " → \"" << *yetAnotherPTR << "\"" << std::endl;

	// ============ DIFFERENT VARIABLES ============
	printSubHeader("🆚 Pointers to different variables");
	std::string heart = "❤️ HEART";
	std::string soul = "👻 SOUL";

	std::string *heartPTR = &heart;
	std::string *soulPTR = &soul;

	std::cout << RED << "heart    : " << RESET << &heart << " → \"" << heart << "\"" << std::endl;
	std::cout << WHITE << "soul     : " << RESET << &soul << " → \"" << soul << "\"" << std::endl;
	std::cout << RED << "heartPTR : " << RESET << heartPTR << " → \"" << *heartPTR << "\"" << std::endl;
	std::cout << WHITE << "soulPTR  : " << RESET << soulPTR << " → \"" << *soulPTR << "\"" << std::endl;

	// ============ POINTER REDIRECTION ============
	printSubHeader("🔄 Redirecting pointer");
	std::cout << YELLOW << "Before - heartPTR points to: " << RESET << "\"" << *heartPTR << "\"" << std::endl;
	heartPTR = &soul; // Now heartPTR points to soul
	std::cout << YELLOW << "After - heartPTR points to: " << RESET << "\"" << *heartPTR << "\"" << std::endl;

	// ============ SIZES ============
	printSubHeader("📏 Sizes in bytes");
	std::cout << WHITE << "sizeof(brain)     : " << RESET << sizeof(brain) << " bytes" << std::endl;
	std::cout << WHITE << "sizeof(stringPTR) : " << RESET << sizeof(stringPTR) << " bytes" << std::endl;
	std::cout << WHITE << "sizeof(stringREF) : " << RESET << sizeof(stringREF) << " bytes" << std::endl;

	// ============ FINAL ============
	printSubHeader("🎯 Final Summary");
	std::cout << GREEN << "✅ References are permanent aliases" << RESET << std::endl;
	std::cout << BLUE << "✅ Pointers can be redirected" << RESET << std::endl;
	std::cout << YELLOW << "✅ Both access the same memory" << RESET << std::endl;
	std::cout << MAGENTA << "✅ Modifications affect the original variable" << RESET << std::endl;

	std::cout << BOLD << CYAN << "\n🏁 End of demonstration!" << RESET << std::endl;
	return (0);
}
