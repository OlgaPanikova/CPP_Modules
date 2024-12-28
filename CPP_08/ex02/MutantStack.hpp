#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack();
	MutantStack<T>::MutantStack(const MutantStack<T>& copy);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

};


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy) {
	std::cout << "MutantStack copy constructor called" << std::endl;
}


template<typename T>
MutantStack& MutantStack<T>::operator=(const MutantStack<T>& other) {
	std::cout << "MutantStack copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
    std::stack<T>::operator=(other);
	return *this;
}

MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

typename std::stack<T>::container_type::iterator begin() {
	return std::stack<T>::c.begin();
}

typename std::stack<T>::container_type::iterator end() {
	return std::stack<T>::c.end();
}

typename std::stack<T>::container_type::reverse_iterator rbegin() {
	return std::stack<T>::c.rbegin();
}

typename std::stack<T>::container_type::reverse_iterator rend() {
	return std::stack<T>::c.rend();
}

#endif