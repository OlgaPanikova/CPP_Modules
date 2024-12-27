#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
  *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

bool isCharacter(const std::string& input) {
    return input.length() == 1 && !isdigit(input[0]);
}

bool isInteger(const std::string& input) {
    size_t idx = 0;
    if (input[0] == '-') idx++;
    for (; idx < input.length(); idx++) {
        if (!isdigit(input[idx])) {
            return false;
        }
    }
    return true;
}

bool isFloatingPoint(const std::string &input) {
    size_t idx = 0;
    if (input[0] == '-') idx++;
    for (; idx < input.length(); idx++) {
        if ((!isdigit(input[idx]) && input[idx] != 'f' && input[idx] != '.') ||
            (input[idx] == 'f' && idx + 1 < input.length())) {
            return false;
        }
    }
    for (size_t idx = 0; idx < input.length(); idx++) {
        if (input[idx] == '.') {
            while (input[idx] != 'f' && idx < input.length()) idx++;
            if (input[idx] == 'f' && idx + 1 == input.length()) {
                return true;
            }
        }
    }

    return false;
}


bool isDoublePrecision(const std::string &input) {
    size_t idx = 0;
    if (input[0] == '-') idx++;

    bool hasDot = false;
    bool hasDigitAfterDot = false;

    for (; idx < input.length(); idx++) {
        char currentChar = input[idx];
        if (currentChar == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        }
        else if (currentChar == 'f') {
            return false;
        }
        else if (isdigit(currentChar)) {
            if (hasDot) {
                hasDigitAfterDot = true;
            }
        }
        else {
            return false;
        }
    }
    return hasDot && hasDigitAfterDot;
}

DataType detectType(const std::string& input) {
    if (isCharacter(input)) return CHARACTER;
    if (isInteger(input)) return INTEGER;
    if (isFloatingPoint(input)) return FLOATING_POINT;
    if (isDoublePrecision(input)) return DOUBLE_PRECISION;
    return INVALID_TYPE;
}

void display(DataType type, const std::string& input) {
	if (type == CHARACTER) {
        std::cout << "Character: ";
        if (input[0] >= 32 && input[0] <= 126)
            std::cout << "'" << input[0] << "'" << std::endl;
        else if ((input[0] >= 0 && input[0] <= 31) || input[0] == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        char value = input[0];
        std::cout << "Integer: " << static_cast<int>(value) << std::endl;
        std::cout << "Float: " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "Double: " << static_cast<double>(value) << ".0" << std::endl;
    }
	else if (type == INTEGER) {
			int i = std::atoi(input.c_str());
        std::cout << "Character: ";
        if (i >= 32 && i <= 126)
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else if ((i >= 0 && i <= 31) || i == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        std::cout << "Integer: " << i << std::endl;
        std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    else if (type == FLOATING_POINT) {
				float	f = std::atof(input.c_str());
        std::cout << "Character: ";
        if (f >= 32 && f <= 126)
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        else if ((f >= 0 && f <= 31) || f == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        std::cout << "Integer: ";
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << static_cast<int>(f) << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        std::cout << "Float: " << f << "f" << std::endl;
        std::cout << "Double: " << static_cast<double>(f) << std::endl;
    }
    else if (type == DOUBLE_PRECISION) {
				double	d = std::atof(input.c_str());
        std::cout << "Character: ";
        if (d >= 32 && d <= 126)
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else if ((d >= 0 && d <= 31) || d == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        std::cout << "Integer: ";
        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << static_cast<int>(d) << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        std::cout << "Float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "Double: " << d << std::endl;
    }
}

bool isSpecialValue(const std::string &input) {
    if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff") {
        std::cout << "Character: Impossible" << std::endl;
        std::cout << "Integer: Impossible" << std::endl;
        std::cout << "Float: inff" << std::endl;
        std::cout << "Double: inf" << std::endl;
        return true;
    }
    else if (input == "-inf" || input == "-inff") {
        std::cout << "Character: Impossible" << std::endl;
        std::cout << "Integer: Impossible" << std::endl;
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
        return true;
    }
    else if (input == "nan" || input == "nanf") {
        std::cout << "Character: Impossible" << std::endl;
        std::cout << "Integer: Impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return true;
    }
    return false;
}


void ScalarConverter::convert(const std::string& input) {
    if (isSpecialValue(input)) {
        return;
    }
    DataType type = detectType(input);
    if (type == INVALID_TYPE) {
        std::cerr << "Error: Invalid input\n";
        return;
    }
    display(type, input);
}