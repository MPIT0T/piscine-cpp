#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, int elem)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == elem)
			return it;
	}
	throw std::runtime_error("Not found");
}

#endif
