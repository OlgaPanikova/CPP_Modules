#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
  void executeAction(const Bureaucrat& executor) const;
	virtual AForm* clone(const std::string& target) const;
	virtual const std::string& getTarget() const;
};


#endif