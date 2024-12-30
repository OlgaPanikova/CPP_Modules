#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack<T>& copy);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();
	typedef typename std::stack<T>::container_type container_type;
	typedef typename container_type::iterator iterator;
  typedef typename container_type::const_iterator const_iterator;
  typedef typename container_type::reverse_iterator reverse_iterator;
  typedef typename container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

};


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy) {
	std::cout << "MutantStack copy constructor called" << std::endl;
}


template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	std::cout << "MutantStack copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
    std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return std::stack<T>::c.end();
}


template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return std::stack<T>::c.rbegin();
}


template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return std::stack<T>::c.rend();
}


template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return std::stack<T>::c.rbegin();
}


template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return std::stack<T>::c.rend();
}

#endif