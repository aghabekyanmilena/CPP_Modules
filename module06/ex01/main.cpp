#include "Serializer.hpp"

int	main()
{
	Data		data;

	data.number = 10;
	data.str = "Hello";
	uintptr_t	tmp = Serializer::serialize(&data);

	std::cout << tmp << std::endl;

	Data*		data1 = Serializer::deserialize(tmp);

	std::cout << data1->number << std::endl;
	std::cout << data1->str << std::endl;

	return (0);
}