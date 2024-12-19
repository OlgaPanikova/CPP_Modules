#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Mr Raccoon") grade(100) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) {
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	this->name = name;
	if (grade < 1) {
		throw GradeTooLowException;
	}
	if (grade > 150) {
		throw GradeTooHighException;
	}
		this->grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}


std::string& Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

