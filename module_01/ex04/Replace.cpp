#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

void Replace::process()
{
	std::string content = readFile();
	if (content.empty())
		return ;

	std::string newContent = replaceString(content);
	writeFile(newContent);
}

std::string Replace::readFile()
{
	std::ifstream inFile(_filename.c_str());
	if (!inFile)
	{
		std::cerr << "❌ Error: could not open file " << _filename << std::endl;
		return ("");
	}

	std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
	inFile.close();
	return (content);
}

std::string Replace::replaceString(const std::string &content)
{
	std::string result;
	size_t pos = 0, found;

	while ((found = content.find(_s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result += content.substr(pos);
	return (result);
}

void Replace::writeFile(const std::string &newContent)
{
	std::ofstream outFile((_filename + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "❌ Error: could not create output file." << std::endl;
		return;
	}
	outFile << newContent;
	outFile.close();
}
