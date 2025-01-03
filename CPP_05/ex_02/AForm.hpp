#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& copy);
	AForm& operator= (const AForm& other);
	virtual ~AForm();

  const std::string& getName() const;
  bool getSigned() const;
  int getGrageToSing() const;
  int getGrageToExecute() const;
  void beSigned(const Bureaucrat& bureaucrat);
  void execute(const Bureaucrat& executor) const;
  virtual void executeAction() const = 0;
  class GradeTooHighException : public std::exception {
  public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char* what() const throw();
  };
  class FormNotSignedException: public std::exception {
  public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif