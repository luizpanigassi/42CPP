#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class Sed
{
	public:
		Sed(std::string filename, std::string s1, std::string s2);
		~Sed();
		bool replace();

	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
};

#endif
