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

  // DataType detectType(const std::string &input);
  // bool isCharacter(const std::string &input);
  // bool isInteger(const std::string &input);
  // bool isFloatingPoint(const std::string &input);
  // bool isDoublePrecision(const std::string &input);
  // void display(DataType type);
  // bool isSpecialValue(const std::string &input);

#endif