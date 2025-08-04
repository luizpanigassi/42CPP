#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(); // default constructor
		Zombie(const std::string& name); // parameterized constructor
		~Zombie();

		std::string getName() const; // name getter
		void setName(const std::string& name); // name setter
		void announce() const;
};

Zombie* zombieHorde(int N, const std::string& name);

#endif
