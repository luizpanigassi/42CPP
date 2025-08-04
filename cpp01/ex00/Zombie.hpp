#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(const std::string& name);
		~Zombie();

		std::string getName() const; // name getter
		void announce() const;
};

#endif
