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


int main() {
    Bureaucrat highRanking("High Ranking", 1);
    Bureaucrat midRanking("Mid Ranking", 75);
    Bureaucrat lowRanking("Low Ranking", 150);

    Form highForm("High Form", 1, 1);
    Form midForm("Mid Form", 75, 75);
    Form lowForm("Low Form", 150, 150);

    std::cout << highRanking << std::endl;
    std::cout << midRanking << std::endl;
    std::cout << lowRanking << std::endl;
    std::cout << highForm << std::endl;
    std::cout << midForm << std::endl;
    std::cout << lowForm << std::endl;

    try {
        Form invalidForm("Invalid Form", 0, 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 151, 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 1, 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 151, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        highForm.beSigned(midRanking);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        midForm.beSigned(lowRanking);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        lowForm.beSigned(highRanking);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << highForm << std::endl;
    std::cout << midForm << std::endl;
    std::cout << lowForm << std::endl;

    try {
        midForm.beSigned(highRanking);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << midForm << std::endl;

    return (0);
}