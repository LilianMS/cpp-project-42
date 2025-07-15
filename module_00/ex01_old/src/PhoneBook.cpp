
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _nextIndex(0), _size(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::promptInput(const std::string &prompt) const {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
    } while (input.empty());
    return (input);
}

void PhoneBook::addContact() {
    Contact contact;
    contact.setField(0, promptInput("First name: "));
    contact.setField(1, promptInput("Last name: "));
    contact.setField(2, promptInput("Nickname: "));
    contact.setField(3, promptInput("Phone number: "));
    contact.setField(4, promptInput("Darkest secret: "));

    if (contact.isComplete()) {
        _contacts[_nextIndex] = contact;
        _nextIndex = (_nextIndex + 1) % 8;
        if (_size < 8)
            _size++;
        std::cout << "✅ Contact added!\n";
    }
}

void PhoneBook::printTable() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < _size; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << _contacts[i].getSummaryField(0) << "|"
                  << std::setw(10) << _contacts[i].getSummaryField(1) << "|"
                  << std::setw(10) << _contacts[i].getSummaryField(2) << "\n";
    }
}

void PhoneBook::printContact(int index) const {
    if (index < 0 || index >= _size) {
        std::cout << "❌ Invalid index.\n";
        return ;
    }

    std::cout << "First Name: " << _contacts[index].getField(0) << "\n";
    std::cout << "Last Name: " << _contacts[index].getField(1) << "\n";
    std::cout << "Nickname: " << _contacts[index].getField(2) << "\n";
    std::cout << "Phone Number: " << _contacts[index].getField(3) << "\n";
    std::cout << "Darkest Secret: " << _contacts[index].getField(4) << "\n";
}

void PhoneBook::searchContacts() const {
    if (_size == 0) {
        std::cout << "📭 PhoneBook is empty.\n";
        return ;
    }

    printTable();

    std::string input;
    std::cout << "Enter the index of the contact to view: ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int index;
    if (iss >> index)
        printContact(index);
    else
        std::cout << "❌ Invalid input.\n";
}


// PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0){}
// PhoneBook::~PhoneBook() {}

// int	PhoneBook::addContact()
// {
// 	contacts[currentIndex].setContactInfo();
// 	currentIndex = (currentIndex + 1) % 8;
// 	if (totalContacts < 8) {
// 		totalContacts++;
// 	}
// 	std::cout << "Contact nº " << currentIndex << " has been successfully added!\n" << std::endl;
// 	return (currentIndex);
// }

// void PhoneBook::searchContact() const
// {
// 	std::string	str;
// 	int			index;
	
// 	if (totalContacts == 0)
// 	{
// 		std::cout << "PhoneBook is empty" << std::endl;
// 		return ;
// 	}
// 	displayContactTable();
// 	std::cout << "*Enter index of contact you are searching: ";
// 	std::getline(std::cin, str);
//     if (str.length() == 1 && str[0] >= '0' && str[0] <= '9')
// 	{
// 		index = str[0] - '0';
// 		if (index < totalContacts && index >= 0)
// 		{
// 			contacts[index].displayContactInfo();
// 			return ;
// 		}
// 	}
// 	std::cout << "Invalid index!" << std::endl;
// 	std::cout << std::endl;
// 	return ;
// }

// void	PhoneBook::displayContactTable(void) const {
// 	insertHeader();
// 	for (int i = 0; i < totalContacts; i++)
// 	{
// 		std::cout << "|" << std::setw(10) << std::right << i << "|";
// 		std::cout << std::setw(10) << truncateData(contacts[i].getFirstName()) << "|";
// 		std::cout << std::setw(10) << truncateData(contacts[i].getLastName()) << "|";
// 		std::cout << std::setw(10) << truncateData(contacts[i].getNickname()) << "|" << std::endl;
// 	}
// 	insertFooter();
// }

// void	PhoneBook::insertFooter(void) const {
// 	std::cout << "|----------|----------|----------|----------|" << std::endl;
// 	std::cout << std::endl;
// }

// void	PhoneBook::insertHeader(void) const {
// 	std::cout << std::endl;
// 	std::cout << "_____________________________________________" << std::endl;
// 	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
// 	std::cout << "|----------|----------|----------|----------|" << std::endl;
// }

// std::string	PhoneBook::truncateData(std::string data) const
// {
// 	std::string	trunc_data;

// 	if (data.length() > 10)
// 	{
// 		trunc_data = data.substr(0, 10);
// 		trunc_data.replace(10, 1, ".");
// 		return (trunc_data);
// 	}
// 	return (data);
// }