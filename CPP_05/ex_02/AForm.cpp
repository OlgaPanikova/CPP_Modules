#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Mr Raccoon"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm parametric constructor called" << std::endl;
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_isSigned;
}

int AForm::getGrageToSing() const {
	return this->_gradeToSign;
}

int AForm::getGrageToExecute() const {
	return this->_gradeToExecute;
}

const char *AForm::GradeTooHighException:: what() const throw()	{
	return "Grade is too high!";
};

const char *AForm::GradeTooLowException:: what() const throw()	{
	return "Grade is too low!";
};

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& aform) {
	os << aform.getName() << ", AForm status: " << (aform.getSigned() ? "signed" : "not signed") << ", Grade to sign: " << aform.getGrageToSing() << ", Grade to execute: " << aform.getGrageToExecute();
	return os;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGrageToExecute())
		throw GradeTooLowException();
	executeAction();
}
