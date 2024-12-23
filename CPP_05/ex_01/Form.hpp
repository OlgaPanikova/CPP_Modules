#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  Form();
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form& copy);
	Form& operator= (const Form& other);
	~Form();

  const std::string& getName() const;
  bool getSigned() const;
  int getGrageToSing() const;
  int getGrageToExecute() const;
  void beSigned(const Bureaucrat& bureaucrat);
  class GradeTooHighException : public std::exception {
  public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif