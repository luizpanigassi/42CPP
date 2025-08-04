#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain started!" << std::endl;
	for (int i = 0; i < 10; ++i)
		this->ideas[i] = "EAT!";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called!" <<std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called!" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain obliterated!" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index <= 0 || index > 100)
	{
		std::cerr << "Nope, your index is too high/low to have ideas!" << std::endl;
		return "";
	}
	return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index <= 0 || index > 100)
	{
		std::cerr << "Nope, your index is too high/low to have ideas!" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
	std::cout << "Idea set at index " << index << ". The idea is: " << ideas[index] << std::endl;
}
