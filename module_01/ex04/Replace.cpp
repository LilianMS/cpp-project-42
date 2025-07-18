#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

bool Replace::process()
{
	if (_s1.empty() || _s2.empty())
	{
		std::cerr << "Error: file, s1 and s2 cannot be empty." << std::endl;
		return (false);
	}
	std::string content;
	if (!readFile(content))
		return (false);
	if (content.empty())
		std::cout << "[!] file " << _filename << " is empty." << std::endl;
	std::string newContent = replaceString(content);
	return (writeFile(newContent));
}

bool Replace::readFile(std::string &content)
{
	std::ifstream inFile(_filename.c_str());
	if (!inFile)
	{
		std::cerr << "Error: could not open file " << _filename << std::endl;
		return (false);
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	inFile.close();
	return (true);
}

std::string Replace::replaceString(const std::string &content)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = content.find(_s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result += content.substr(pos);
	return (result);
}

bool Replace::writeFile(const std::string &newContent)
{
	std::string outFileName = _filename + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!outFile)
	{
		std::cerr << "Error: could not create output file "
				  << outFileName << std::endl;
		return (false);
	}
	outFile << newContent;
	outFile.close();
	return (true);
}
