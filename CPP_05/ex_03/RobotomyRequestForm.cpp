#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
  AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction() const {
  std::cout << "*Drilling noises*: Dzzz... Dzzzz....Dzzzzzzz.." << std::endl;
  if (std::rand() % 2)
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "Robotomy of " << _target << " failed!" << std::endl;
}

AForm* RobotomyRequestForm::clone(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}