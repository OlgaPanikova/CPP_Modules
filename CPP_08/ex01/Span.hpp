#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

class Span {
private:
  std::vector<int> _numbers;
  unsigned int N;

public:
	Span();
  Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& other);
	~Span();
  void addNumber(int number);
  int shortestSpan() const;
};

#endif