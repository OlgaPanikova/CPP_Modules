#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr Raccoon"), grade(100) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name){
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1) {
		throw GradeTooLowException();
	}
	if (grade > 150) {
		throw GradeTooHighException();
	}
		this->grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), grade(copy.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException:: what() const throw()	{
		return "Grade is too high!";
};

const char *Bureaucrat::GradeTooLowException:: what() const throw()	{
		return "Grade is too low!";
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
		os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
		return os;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
