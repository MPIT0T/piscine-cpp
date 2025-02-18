#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
/* Methods */
	static void convert(const std::string &literal);

private:
/* Constructors */
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();

/* Operators */
	ScalarConverter &operator=(const ScalarConverter &src);

/* Methods */
	static void		put_types(char c, int i, float f, double d);

	static int		toChar(const std::string &literal);
	static int		toInt(const std::string &literal);
	static int		toFloat(const std::string &literal);
	static int		toDouble(const std::string &literal);
	static int		toSpec(const std::string &literal);
	static int		toImpossible();

};



#endif //SCALARCONVERTER_HPP
