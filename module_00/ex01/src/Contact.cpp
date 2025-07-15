#include "Contact.hpp"
#include <iomanip>

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setField(int fieldIndex, const std::string &value)
{
	if (fieldIndex >= 0 && fieldIndex < 5)
		_fields[fieldIndex] = value;
}

std::string Contact::getField(int fieldIndex) const
{
	if (fieldIndex >= 0 && fieldIndex < 5)
		return (_fields[fieldIndex]);
	return ("");
}

std::string Contact::getSummaryField(int fieldIndex) const
{
	if (fieldIndex < 0 || fieldIndex >= 5)
		return "";
	std::string str = _fields[fieldIndex];
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

bool Contact::isComplete() const
{
	for (int i = 0; i < 5; i++)
	{
		if (_fields[i].empty())
			return (false);
	}
	return (true);
}
