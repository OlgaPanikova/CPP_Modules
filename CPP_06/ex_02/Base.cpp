#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    int random = rand() % 3;

    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); // Попытка преобразовать к типу A
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p); // Попытка преобразовать к типу B
        std::cout << "B" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p); // Попытка преобразовать к типу C
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {}
}