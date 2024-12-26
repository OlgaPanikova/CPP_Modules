#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 100, 50);

        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);

        std::cout << taxForm << std::endl;

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
