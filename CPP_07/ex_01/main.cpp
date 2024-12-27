#include "iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printElement);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArray, 4, printElement);

    std::string stringArray[] = {"Hello", "world", "C++"};
    iter(stringArray, 3, printElement);

    return 0;
}
