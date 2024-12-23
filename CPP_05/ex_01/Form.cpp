#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Mr Raccoon"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form parametric constructor called" << std::endl;
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_isSigned;
}

int Form::getGrageToSing() const {
	return this->_gradeToSign;
}

int Form::getGrageToExecute() const {
	return this->_gradeToExecute;
}

const char *Form::GradeTooHighException:: what() const throw()	{
		return "Grade is too high!";
};

const char *Form::GradeTooLowException:: what() const throw()	{
		return "Grade is too low!";
};

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << form.getName() << ", Form status: "
    << (form.getSigned() ? "signed" : "not signed")
       << ", Grade to sign: " << form.getGrageToSing()
       << ", Grade to execute: " << form.getGrageToExecute();
    return os;
}
