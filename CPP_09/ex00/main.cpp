#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");

        if (!exchange.validateAndProcessFile(argv[1])) {
            throw std::runtime_error("Error processing input file.");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
