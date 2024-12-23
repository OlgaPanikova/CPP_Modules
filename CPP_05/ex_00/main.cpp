#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("John", 1);  // Создаем бюрократа с оценкой 1 (наивысшая)
        std::cout << b << std::endl;

        // Пробуем увеличить и уменьшить оценку
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;

        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;

        Bureaucrat b2("Alice", 150);  // Создаем бюрократа с оценкой 150 (низшая)
        std::cout << b2 << std::endl;

        b2.incrementGrade();
        std::cout << "After increment: " << b << std::endl;

        b2.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;

        // Тестирование некорректной оценки
        Bureaucrat b3("Bob", 0);  // Некорректная оценка, будет выброшено исключение
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}