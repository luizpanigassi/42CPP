#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2)
{
	std::cout << "Sed created for file: " << _filename << std::endl;
	std::cout << "Replacing '" << _s1 << "' with '" << _s2 << "'." << std::endl;
}

Sed::~Sed()
{
	std::cout << "Sed object for file " << _filename << " destroyed." << std::endl;
}

bool Sed::replace()
{
	std::ifstream infile(_filename.c_str());
	if(!infile.is_open())
	{
		std::cerr << "Error opening the file: " << _filename << std::endl;
		return false;
	}
	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();

	if (content.empty())
	{
		std::cerr << "Not a big deal, but your file is empty. No replacement for you." << std::endl;
		return true;
	}

	if(_s1.empty())
	{
		std::cerr << "Error: string to replace (s1) can't be empty." << std::endl;
		return false;
	}

	if(_s2.empty())
	{
		std::cerr << "Not a problem, but string to be replaced with (s2) shouldn't be empty." << std::endl;
		return false;
	}

	if(_s1 == _s2)
	{
		std::cerr << "Don't try to be funny. Both strings are the same!" << std::endl;
		return true;
	}

	size_t first_occurrence = content.find(_s1);
	if(first_occurrence == std::string::npos)
	{
		std::cerr << "String s1 ('" << _s1 << "') not found in the file, no replacement made." << std::endl;
		return true;
	}

	std::string result;
	size_t pos = 0;
	size_t found;

	while((found = content.find(_s1, pos)) != std::string::npos)
	{
		result.append(content.substr(pos, found - pos));
		result.append(_s2);
		pos = found + _s1.length();
	}
	result.append(content.substr(pos));

	std::ofstream outfile((_filename + "_replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error creating the output file: " << _filename << "_replace" << std::endl;
		return false;
	}
	outfile << result;
	outfile.close();

	std::cout << "Replacement completed! Check the file: " << _filename << "_replace" << std::endl;
	return true;
}
