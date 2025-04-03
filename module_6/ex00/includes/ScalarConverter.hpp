#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &src);

	static void		put_types(const char &c, const int &i, const float &f, const double &d);

	static int		toChar(const std::string &literal);
	static int		toInt(const std::string &literal);
	static int		toFloat(const std::string &literal);
	static int		toDouble(const std::string &literal);
	static int		toSpec(const std::string &literal);
	static int		toImpossible();

};



#endif
