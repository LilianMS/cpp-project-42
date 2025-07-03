
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>


PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0){}
PhoneBook::~PhoneBook() {}

int	PhoneBook::addContact()
{
	contacts[currentIndex].setContactInfo();
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8) {
		totalContacts++;
	}
	std::cout << "Contact nº " << currentIndex << " has been successfully added!\n" << std::endl;
	return (currentIndex);
}

void PhoneBook::searchContact() const
{
	std::string	str;
	int			index;
	
	if (totalContacts == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	displayContactTable();
	std::cout << "*Enter index of contact you are searching: ";
	std::getline(std::cin, str);
    if (str.length() == 1 && str[0] >= '0' && str[0] <= '9')
	{
		index = str[0] - '0';
		if (index < totalContacts && index >= 0)
		{
			contacts[index].displayContactInfo();
			return ;
		}
	}
	std::cout << "Invalid index!" << std::endl;
	std::cout << std::endl;
	return ;
}

void	PhoneBook::displayContactTable(void) const {
	insertHeader();
	for (int i = 0; i < totalContacts; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << truncateData(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateData(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateData(contacts[i].getNickname()) << "|" << std::endl;
	}
	insertFooter();
}

void	PhoneBook::insertFooter(void) const {
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::insertHeader(void) const {
	std::cout << std::endl;
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

std::string	PhoneBook::truncateData(std::string data) const
{
	std::string	trunc_data;

	if (data.length() > 10)
	{
		trunc_data = data.substr(0, 9);
		trunc_data.replace(9, 1, ".");
		return (trunc_data);
	}
	return (data);
}