#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    srand(static_cast<unsigned>(time(0)));

    Base* obj = generate(); // Случайный объект
    std::cout << "Identify by pointer: ";
    identify(obj);

    std::cout << "Identify by reference: ";
    identify(*obj);

    delete obj; // Освобождаем память
    return 0;
}