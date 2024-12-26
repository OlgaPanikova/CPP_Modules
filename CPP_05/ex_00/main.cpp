#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("John", 1);
        std::cout << b << std::endl;

        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
        
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;


        Bureaucrat b2("Alice", 150);
        std::cout << b2 << std::endl;

        b2.incrementGrade();
        std::cout << "After increment: " << b << std::endl;

        b2.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;

        Bureaucrat b3("Bob", 0);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}