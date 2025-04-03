#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data myData = {42};

	std::cout << "Original Data address: " << &myData << "\n";

	uintptr_t raw = Serializer::serialize(&myData);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized Data address: " << deserializedData << "\n";

	if (deserializedData == &myData)
	{
		std::cout << "Success: The deserialized pointer matches the original.\n";
		std::cout << "ID: " << deserializedData->num << std::endl;
	}
	else
	{
		std::cout << "Error: Pointers do not match!\n";
	}

	return 0;
}
