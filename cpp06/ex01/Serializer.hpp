#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

#include "Data.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
// Constructors and Destructor
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
};

#endif
