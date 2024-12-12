#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow, Meow" << std::endl;
}