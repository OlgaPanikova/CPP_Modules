#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <fstream>

  enum DataType {
        CHARACTER,
        INTEGER,
        FLOATING_POINT,
        DOUBLE_PRECISION,
        INVALID_TYPE
    };

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
  static void convert(const std::string &input);
};

#endif