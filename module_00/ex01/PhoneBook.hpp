#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		
		int		addContact();
		void	searchContact() const;

	private:
		Contact		contacts[8];
		int			currentIndex;
		int			totalContacts;
		
		void		displayContactTable() const;
		void		insertFooter() const;
		void		insertHeader() const;
		std::string	truncateData(std::string data) const;
};

#endif // PHONEBOOK_HPP
