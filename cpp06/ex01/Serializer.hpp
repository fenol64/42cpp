#pragma once

#include <iostream>
#include <cstdint>

struct Data
{
	std::string	role;
	unsigned int	power;
};


class Serializer {
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &src);
		~Serializer(void);
};