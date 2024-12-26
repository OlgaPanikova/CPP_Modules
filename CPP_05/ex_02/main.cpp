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
