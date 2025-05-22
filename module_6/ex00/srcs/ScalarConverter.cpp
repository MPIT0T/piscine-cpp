#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void) src;
	return *this;
}

void ScalarConverter::put_types(const char &c, const int &i, const float &f, const double &d)
{
	if (i > 127 || i < 0)
		std::cout << "[  char] : impossible" << std::endl;
	else if (i < 9 || (i > 11 && i < 32) || i == 127)
		std::cout << "[  char] : non displayable" << std::endl;
	else
		std::cout << "[  char] : " << c << std::endl;

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "[   int] : impossible" << std::endl;
	else
		std::cout << "[   int] : " << i << std::endl;

	if (f < 1000000 && f > -1000000 && i - d == 0)
	{
		std::cout << "[ float] : " << f << ".0f" << std::endl;
		std::cout << "[double] : " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "[ float] : " << f << "f" << std::endl;
		std::cout << "[double] : " << d << std::endl;
	}
}

int ScalarConverter::toChar(const std::string& literal)
{
	if (literal[1] || (literal[0] >= '0' && literal[0] <= '9'))
		return 1;
	std::cout << "---[char]---" << std::endl << std::endl;
	put_types(literal[0], static_cast<int>(literal[0]), static_cast<float>(literal[0]), static_cast<double>(literal[0]));
	return 0;
}

int ScalarConverter::toInt(const std::string& literal)
{
	std::stringstream ss(literal);
	int i;
	ss >> i;
	if (!ss.eof() || ss.fail())
		return 1;
	std::cout << "---[int]---" << std::endl;
	put_types(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
	return 0;
}

int ScalarConverter::toFloat(const std::string& literal)
{
	std::stringstream ss(literal);
	float f;
	ss >> f;
	if (ss.eof() || ss.fail() || literal[literal.length() - 1] != 'f')
		return 1;
	std::cout << "---[float]---" << std::endl;
	put_types(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
	return 0;
}

int ScalarConverter::toDouble(const std::string& literal)
{
	std::stringstream ss(literal);
	double d;
	ss >> d;
	if (!ss.eof() || ss.fail())
		return 1;
	std::cout << "---[double]---" << std::endl;
	put_types(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
	return 0;
}

int ScalarConverter::toSpec(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "[  char] : impossible" << std::endl;
		std::cout << "[   int] : impossible" << std::endl;
		std::cout << "[ float] : " << literal << "f" << std::endl;
		std::cout << "[double] : " << literal << std::endl;
		return 0;
	}
	if (literal == "+inff" || literal == "-inff")
	{
		std::cout << "[  char] : impossible" << std::endl;
		std::cout << "[   int] : impossible" << std::endl;
		std::cout << "[ float] : " << literal << std::endl;
		std::cout << "[double] : " << literal.substr(0, 4) << std::endl;
		return 0;
	}
	if (literal == "nanf")
	{
		std::cout << "[  char] : impossible" << std::endl;
		std::cout << "[   int] : impossible" << std::endl;
		std::cout << "[ float] : " << literal << std::endl;
		std::cout << "[double] : " << literal.substr(0, 3) << std::endl;
		return 0;
	}
	return 1;
}

int ScalarConverter::toImpossible()
{
	std::cout << "[  char] : impossible" << std::endl;
	std::cout << "[   int] : impossible" << std::endl;
	std::cout << "[ float] : impossible" << std::endl;
	std::cout << "[double] : impossible" << std::endl;
	return 0;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (toChar(literal) == 0)
		return ;
	if (toInt(literal) == 0)
		return ;
	if (toFloat(literal) == 0)
		return ;
	if (toDouble(literal) == 0)
		return ;
	if (toSpec(literal) == 0)
		return ;
	toImpossible();
}
