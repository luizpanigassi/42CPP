#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>

class HumanB
{
	public:
		void attack() const;
		void setWeapon(class Weapon& weapon); // setter for weapon

		std::string getName() const; // name getter
		HumanB(const std::string& name); // parameterized constructor
		~HumanB(); // destructor

	private:
		std::string name;
		Weapon* weapon; // pointer to a Weapon object
};

#endif
