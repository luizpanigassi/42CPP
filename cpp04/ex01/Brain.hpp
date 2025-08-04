#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain {
public:
	// Constructors and Destructor
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

private:
	std::string ideas[100];
};

#endif
