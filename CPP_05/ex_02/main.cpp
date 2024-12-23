#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat john("John", 5);
    ShrubberyCreationForm form1("home");
    RobotomyRequestForm form2("robot");
    PresidentialPardonForm form3("Alice");

    try {
        form1.beSigned(john);
        john.executeForm(form1);

        form2.beSigned(john);
        john.executeForm(form2);

        form3.beSigned(john);
        john.executeForm(form3);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


int main() {
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2("Bureaucrat2", 150);
    Bureaucrat b3("Bureaucrat3", 75);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    ShrubberyCreationForm f1("ShrubberyCreationForm1");
    RobotomyRequestForm f2("RobotomyRequestForm1");
    PresidentialPardonForm f3("PresidentialPardonForm1");

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    try {
        b1.signForm(f1);
        b1.executeForm(f1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        b2.signForm(f2);
        b2.executeForm(f2);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        b3.signForm(f3);
        b3.executeForm(f3);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}