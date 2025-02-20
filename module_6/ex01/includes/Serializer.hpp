#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
public:

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
/* Constructors */
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();

/* Operators */
	Serializer &operator=(const Serializer &src);
};



#endif //SERIALIZER_HPP
