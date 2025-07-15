#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		void		setField(int fieldIndex, const std::string &value);
		std::string	getField(int fieldIndex) const;
		std::string	getSummaryField(int fieldIndex) const;
		bool		isComplete() const;

	private:
		std::string _fields[5];
};

#endif
