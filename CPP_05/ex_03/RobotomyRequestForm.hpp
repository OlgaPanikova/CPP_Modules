#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
public:
	RobotomyRequestForm ();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
  void executeAction(const Bureaucrat& executor) const;
	virtual AForm* clone(const std::string& target) const;
	virtual const std::string& getTarget() const;
};


#endif