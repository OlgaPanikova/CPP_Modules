#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this =  copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    if (this != &other) {
        this->date = other.date;
        this->rate = other.rate;
        this->bitcoinRates = other.bitcoinRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: Cannot open database file.");
    }
    std::string line, date;
    double rate;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && iss >> rate) {
            bitcoinRates[date] = rate;
        } 
    }
    file.close();
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day)) {
        return false;
    }

    if (year < 2000 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDays = daysInMonth[month - 1];

    if (month == 2 && isLeapYear(year)) {
        maxDays = 29;
    }

    return day <= maxDays;
}


bool BitcoinExchange::validateAndProcessFile(const std::string& inFile) {
        std::ifstream infile(inFile.c_str());
        if (!infile.is_open()) {
            std::cerr << "Error: could not open input file." << std::endl;
            return false;
        }

        std::string line;
        if (std::getline(infile, line)) {
            if (line != "date | value") {
                std::cerr << "Error: first line must be 'date | value'." << std::endl;
                return false;
            }
        }

        while (std::getline(infile, line)) {
            processLine(line);
        }

        infile.close();
        return true;
    }

   void BitcoinExchange::processLine(const std::string& line) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (!(std::getline(iss, date, '|') && std::getline(iss, valueStr))) {
            std::cerr << "Error: bad input format => " << line << std::endl;
            return;
        }

        date = date.substr(0, date.find_last_not_of(" ") + 1);
        valueStr = valueStr.substr(valueStr.find_first_not_of(" "));
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            return;
        }
        if (!isValidValue(valueStr)) {
            return;
        }

        double value = std::atof(valueStr.c_str());
        std::string closestDate = findClosestDate(date);
        double rate = bitcoinRates[closestDate];
        double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    bool BitcoinExchange::isValidValue(const std::string& value) const {
        char* end;
        double val = std::strtod(value.c_str(), &end);
        if (*end != '\0' || val < 0 || val > 2000) {
            std::cerr << "Error: ";
            if (*end != '\0' || val < 0) {
                std::cerr << "not a positive number.";
            } else {
                std::cerr << "too large a number.";
            }
            std::cerr << std::endl;
            return false;
        }
        return true;
    }

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
        std::map<std::string, double>::const_iterator it = bitcoinRates.lower_bound(date);
        if (it == bitcoinRates.end() || it->first != date) {
            if (it != bitcoinRates.begin()) --it;
        }
        return it->first;
    }
