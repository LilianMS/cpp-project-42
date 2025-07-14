
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _nextIndex(0), _size(0) {}
PhoneBook::~PhoneBook() {}

int PhoneBook::check_input_data(const std::string &input, const std::string &prompt) const
{
	// Check for empty or whitespace-only input, or too long, or consecutive/leading/trailing spaces
	if (
		input.find_first_not_of(" \t\n\r") == std::string::npos
		|| input.find("  ") != std::string::npos
		|| (!input.empty() && (input[0] == ' '
			|| input[input.length() - 1] == ' ')) // leading/trailing space
	)
	{
		std::cout << "❌ Invalid input. Field cannot be empty or contain leading/trailing/consecutive spaces." << std::endl;
		return (0);
	}
	if (prompt.find("Phone number: ") != std::string::npos &&
		input.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "❌ Invalid input. Only numbers are allowed for phone number." << std::endl;
		return (0);
	}
	if (prompt.find("Phone number: ") == std::string::npos &&
		input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos)
	{
		std::cout << "❌ Invalid input. Only letters and spaces are allowed." << std::endl;
		return (0);
	}
	if (input.length() > 50)
	{
		std::cout << "❌ Invalid input. Field cannot exceed 50 characters." << std::endl;
		return (0);
	}
	return (1);
}

std::string PhoneBook::promptInput(const std::string &prompt) const
{
	std::string input;
	do {
		std::cout << prompt;
		// std::getline(std::cin, input);
		if (!std::getline(std::cin, input))
		{
			// std::cout << "\n👋 EOF received. Exiting program." << std::endl;
			// break ;
			return ""; // Return empty string if EOF is received
		}

		if (!check_input_data(input, prompt))
			continue;
		else
			break ;

	// } while (input.empty());
	} while (true);
	return (input);
}

void PhoneBook::addContact()
{
	Contact contact;
	contact.setField(0, promptInput("First name: "));
	contact.setField(1, promptInput("Last name: "));
	contact.setField(2, promptInput("Nickname: "));
	contact.setField(3, promptInput("Phone number: "));
	contact.setField(4, promptInput("Darkest secret: "));

	if (contact.isComplete())
	{
		_contacts[_nextIndex] = contact;
		_nextIndex = (_nextIndex + 1) % 8;
		if (_size < 8)
			_size++;
		std::cout << "✅ Contact added!\n";
	}
}

void PhoneBook::printTable() const
{
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _size; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << _contacts[i].getSummaryField(0) << "|"
				<< std::setw(10) << _contacts[i].getSummaryField(1) << "|"
				<< std::setw(10) << _contacts[i].getSummaryField(2) << std::endl;
	}
}

void PhoneBook::printContact(int index) const
{
	if (index < 0 || index >= _size)
	{
		std::cout << "❌ Invalid index." << std::endl;
		return ;
	}

	std::cout << "First Name: " << _contacts[index].getField(0) << std::endl;
	std::cout << "Last Name: " << _contacts[index].getField(1) << std::endl;
	std::cout << "Nickname: " << _contacts[index].getField(2) << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getField(3) << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getField(4) << std::endl;
}

void PhoneBook::searchContacts() const
{
	if (_size == 0)
	{
		std::cout << "📭 PhoneBook is empty." << std::endl;
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
		std::cout << "❌ Invalid input." << std::endl;
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
