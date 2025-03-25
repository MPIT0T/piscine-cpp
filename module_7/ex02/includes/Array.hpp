#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
public:
	Array(): _data(NULL), _size(0) {};
	Array(unsigned int n): _data(new T[n]), _size(n) {};
	Array(const Array &src) : _data(NULL), _size(0) {*this = src;};

	Array &operator=(const Array &src)
	{
		if (this != &src)
		{
			 if (_data != NULL)
			 	delete[] _data;
			_size = src._size;
			_data = new T[src._size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = src._data[i];
		}
		return (*this);
	}

	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw (std::out_of_range("Index out of range"));
		return (_data[i]);
	}

	unsigned int size() const {return (_size);};

private:
	T				*_data;
	unsigned int	_size;
};

#endif
