#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib>

class BitcoinExchange {
private:
    std::string date;
    double rate;
    std::map<std::string, double> bitcoinRates;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date);
    bool validateAndProcessFile(const std::string& inFile);
    void processLine(const std::string& line);
    bool isValidValue(const std::string& value) const;
    std::string findClosestDate(const std::string& date) const;
  
};


#endif