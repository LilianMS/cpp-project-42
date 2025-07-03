
#include "Contact.hpp"
#include <cstdlib>

Contact::Contact()
	: firstName(""),
	lastName(""),
	nickname(""),
	phoneNumber(""),
	darkestSecret("")
{
}

Contact::Contact(const std::string &firstName,
				const std::string &lastName,
				const std::string &nickname,
				const std::string &phoneNumber,
				const std::string &darkestSecret)
	: firstName(firstName),
	lastName(lastName),
	nickname(nickname),
	phoneNumber(phoneNumber),
	darkestSecret(darkestSecret)
{
}

Contact::~Contact() {}

const std::string &Contact::getFirstName() const {
	return firstName;
}
const std::string &Contact::getLastName() const {
	return lastName;
}
const std::string &Contact::getNickname() const {
	return nickname;
}
const std::string &Contact::getPhoneNumber() const {
	return phoneNumber;
}
const std::string &Contact::getDarkestSecret() const {
	return darkestSecret;
}

std::string	Contact::getInput(std::string prompt)
{
	std::string input;
	
	std::cout << prompt;
	while (std::getline(std::cin, input)) {
		if (!input.empty()) {
			break;
		}
		std::cout << "Input cannot be empty." << std::endl;
		std::cout << prompt;
	}
	if (std::cin.eof()) {
		std::cout << "\nEOF detected. Exiting program." << std::endl;
		exit(0);
	}
	return input;
}

void	Contact::setContactInfo()
{
	this->firstName = getInput("Enter first name: ");
	this->lastName = getInput("Enter last name: ");
	this->nickname = getInput("Enter nickname: ");
	this->phoneNumber = getInput("Enter phone number: ");
	this->darkestSecret = getInput("Enter darkest secret: ");
}

void	Contact::displayContactInfo(void) const
{
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << '\n' << std::endl;
}