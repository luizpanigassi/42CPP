#include "Base.hpp"
#include "Elements.hpp"

Base::~Base() {}

Base* generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "p: A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "p: B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "p: C" << std::endl;
	else
		std::cout << "Pointer is null or unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "ref: A" << std::endl;
		return;
	}
	catch (...){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "ref: B" << std::endl;
		return;
	}
	catch (...){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "ref: C" << std::endl;
		return;
	}
	catch (...){}

	std::cout << "Reference is of unknown type" << std::endl;
}
