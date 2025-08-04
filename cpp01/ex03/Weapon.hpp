#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(const std::string& type); // parameterized constructor
		~Weapon(); // destructor
		const std::string& getType() const; // type getter
		void setType(const std::string& type); // type setter
};

#endif
