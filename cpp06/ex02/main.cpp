#include "Base.hpp"
#include "Elements.hpp"

int main()
{
	std::srand(std::time(0));

	Base* base = generate();

	identify(base);
	identify(*base);
	delete base;

	return 0;
}
