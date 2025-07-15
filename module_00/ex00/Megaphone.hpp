#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>
#include <string>

class Megaphone
{
	public:
		Megaphone();
		~Megaphone();
		void project(int argc, char **argv) const;

	private:
		void toUpperCase(std::string &str) const;
		void noArg() const;
};

#endif
