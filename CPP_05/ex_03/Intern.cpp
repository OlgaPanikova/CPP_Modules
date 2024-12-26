#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
  form[0] = new ShrubberyCreationForm("default");
  form[1] = new RobotomyRequestForm("default");
  form[2] = new PresidentialPardonForm("default");
}

Intern::Intern(const Intern& copy) {
  std::cout << "Intern copy constructor called" << std::endl;
  *this = copy;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called" << std::endl;

    // Проверяем на самоприсваивание
    if (this == &other) {
        return *this;
    }

    // Освобождаем старые формы
    for (int i = 0; i < 3; ++i) {
        delete form[i];  // Удаляем старые формы
    }

    // Копируем формы из другого объекта
    for (int i = 0; i < 3; ++i) {
        form[i] = other.form[i] ? other.form[i]->clone(other.form[i]->getTarget()) : nullptr;
    }

    return *this;  // Возвращаем текущий объект для поддержки цепочки присваиваний
}

Intern::~Intern() {
std::cout << "Intern destructor called" << std::endl;    
for (int i = 0; i < 3; i++) {
        delete form[i];
    }
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {
  std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      AForm *newForm = form[i]->clone(target);
      return newForm;
    }
  }
  throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}
