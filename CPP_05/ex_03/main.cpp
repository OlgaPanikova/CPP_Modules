#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat bureaucrat("bureaucrat", 1);
    AForm *form;

    form = intern.makeForm("shrubbery creation", "target");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("robotomy request", "target");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("presidential pardon", "target");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    try {
        form = intern.makeForm("nonexistent form", "target");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}