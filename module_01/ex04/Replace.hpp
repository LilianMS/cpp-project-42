#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace {
public:
	Replace(const std::string& filename, const std::string& s1, const std::string& s2);
	~Replace();

	void process();

private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	std::string readFile();
	std::string replaceString(const std::string& content);
	void 		writeFile(const std::string& newContent);
};

#endif
