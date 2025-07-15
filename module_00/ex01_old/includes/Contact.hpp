#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
public:
    Contact();
    ~Contact();

    void setField(int fieldIndex, const std::string &value);
    std::string getField(int fieldIndex) const;

    std::string getSummaryField(int fieldIndex) const;
    bool isComplete() const;

private:
    std::string _fields[5];

    static const int FIRST_NAME = 0;
    static const int LAST_NAME = 1;
    static const int NICKNAME = 2;
    static const int PHONE_NUMBER = 3;
    static const int DARKEST_SECRET = 4;
};

#endif
