#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;

private:
    Contact _contacts[8];
    int     _nextIndex;
    int     _size;

    void printTable() const;
    void printContact(int index) const;
    std::string promptInput(const std::string &prompt) const;
};

#endif
