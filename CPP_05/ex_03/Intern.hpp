#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;
class Bureaucrat;

class Intern {
private:
	AForm* form[3];
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);
	~Intern();
	AForm* makeForm(const std::string &formName, const std::string &target);
	class FormNotFoundException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};


#endif