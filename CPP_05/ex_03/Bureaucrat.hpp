#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	int								grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator= (const Bureaucrat& other);
	~Bureaucrat();
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
};
void signForm(AForm& form);
void executeForm(const AForm& form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif