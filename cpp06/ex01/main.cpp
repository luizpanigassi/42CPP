#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data data;
	data.i = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Testing using INT" << std::endl;
	std::cout << GREEN << "Original address: " << RESET << &data << "," << GREEN << " i: " << RESET << data.i << std::endl;
	std::cout << GREEN << "Serialized (uintptr_t): " << RESET << raw << std::endl;
	std::cout << GREEN << "Deserialized address: " << RESET << deserializedData << "," << GREEN << " i: " << RESET << deserializedData->i << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Testing using CHAR" << std::endl;
	data.c = 'a';
	raw = Serializer::serialize(&data);
	deserializedData = Serializer::deserialize(raw);
	std::cout << GREEN << "Original address: " << RESET << &data << "," << GREEN << " c: " << RESET << data.c << std::endl;
	std::cout << GREEN << "Serialized (uintptr_t): " << RESET << raw << std::endl;
	std::cout << GREEN << "Deserialized address: " << RESET << deserializedData << "," << GREEN << " c: " << RESET << deserializedData->c << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Testing using FLOAT" << std::endl;
	data.f = 3.14f;
	raw = Serializer::serialize(&data);
	deserializedData = Serializer::deserialize(raw);
	std::cout << GREEN << "Original address: " << RESET << &data << "," << GREEN << " f: " << RESET << data.f << std::endl;
	std::cout << GREEN << "Serialized (uintptr_t): " << RESET << raw << std::endl;
	std::cout << GREEN << "Deserialized address: " << RESET << deserializedData << "," << GREEN << " f: " << RESET << deserializedData->f << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Testing using DOUBLE" << std::endl;
	data.d = 2.71828;
	raw = Serializer::serialize(&data);
	deserializedData = Serializer::deserialize(raw);
	std::cout << GREEN << "Original address: " << RESET << &data << "," << GREEN << " d: " << RESET << data.d << std::endl;
	std::cout << GREEN << "Serialized (uintptr_t): " << RESET << raw << std::endl;
	std::cout << GREEN << "Deserialized address: " << RESET << deserializedData << "," << GREEN << " d: " << RESET << deserializedData->d << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return 0;
}
