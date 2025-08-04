#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void test_polymorphism(void)
{
	std::cout << "*** TESTING POLYMORPHISM ***" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl;

	std::cout << "Types: " << j->getType() << " and " << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
}

void test_deepCopy(void)
{
	std::cout << "*** TESTING DEEP COPY ***" << std::endl;
	Cat original;
	std::cout << std::endl;

	Cat copy(original);
	std::cout << std::endl;

	std::cout << "Original brain address: " << original.getBrain() << std::endl;
	std::cout << "Copy brain address: " << copy.getBrain() << std::endl;
	std::cout << std::endl;

	std::cout << "*** TESTING ASSIGNMENT ***" << std::endl;
	Cat assigned;
	std::cout << std::endl;

	assigned = original;
	std::cout << std::endl;

	std::cout << "Original brain address: " << original.getBrain() << std::endl;
	std::cout << "Assigned brain address: " << assigned.getBrain() << std::endl;

	std::cout << std::endl;
}

void test_brainIdeas(void)
{
	std::cout << "*** TESTING BRAIN IDEAS ***" << std::endl;

	Dog kiko;
	kiko.getBrain()->setIdea(1, "sleep...");

	std::cout << std::endl;
	std::cout << kiko.getBrain()->getIdea(0) << std::endl;
	std::cout << kiko.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
}

void test_animalsArray(void)
{
	std::cout << "*** TESTING ARRAY OF ANIMALS ***" << std::endl;
	Animal *animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete (animals[i]);
}

int main(void)
{

	test_polymorphism();
	std::cout << std::endl;

	test_deepCopy();
	std::cout << std::endl;

	test_brainIdeas();
	std::cout << std::endl;

	test_animalsArray();
}
