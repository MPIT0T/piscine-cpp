#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <climits>
# include <iostream>

template <typename T>
int easyfind(const T &container, int elem)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), elem);
	if (it == container.end())
		throw std::runtime_error("Not found");
	return *it;
}

#endif //EASYFIND_HPP
