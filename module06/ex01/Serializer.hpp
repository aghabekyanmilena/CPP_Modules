#pragma once

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

// uintptr_t unsigned integer type that is capable of storing any object pointer value

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};