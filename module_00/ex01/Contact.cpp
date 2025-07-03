
#include "Contact.hpp"

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

void Contact::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}
void Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}
void Contact::setNickname(const std::string &nickname) {
	this->nickname = nickname;
}
void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->darkestSecret = darkestSecret;
}


Contact::Contact(std::string empty) :
	firstName(empty),
	lastName(empty),
	nickname(empty),
	phoneNumber(empty),
	darkestSecret(empty)
{
	return ;
}

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void) 
{
	return ;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

std::string	Contact::getInput(std::string prompt)
{
	std::string input;
	
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting program." << std::endl;
				exit(0);
			}
		}
		if (input.empty()) {
			std::cout << "Input cannot be empty. Please, try again." << std::endl;
		}
	} while (input.empty());
	return input;
}

void	Contact::setContactInfo(void)
{
	this->_firstName = getInput("Enter first name: ");
	this->_lastName = getInput("Enter last name: ");
	this->_nickname = getInput("Enter nickname: ");
	this->_phoneNumber = getInput("Enter phone number: ");
	this->_darkestSecret = getInput("Enter darkest secret: ");
}

void	Contact::displayContactInfo(void) const
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << '\n' << std::endl;
}