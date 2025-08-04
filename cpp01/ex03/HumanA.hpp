#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>

class HumanA
{
	public:
		void attack() const;
		std::string getName() const; // name getter

		HumanA(const std::string& name, class Weapon& weapon);
		~HumanA();

	private:
		std::string name;
		class Weapon& weapon; // reference to a Weapon object
};

#endif
