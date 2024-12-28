#include "Span.hpp"

Span::Span() : N(0){
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : N(N) {
  std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span& copy) : N(copy.N){
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->N = other.N;
  this->_numbers = other._numbers;
  return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number) {
  if (_numbers.size() >= N) {
    throw std::overflow_error("Span is already full");
  }
  _numbers.push_back(number);
}

int Span::shortestSpan() const {
  if (_numbers.size() < 2) {
    throw std::logic_error("Not enough numbers to calculate a span");
  }
  std::vector<int> sorted = _numbers;
  std::sort(sorted.begin(), sorted.end());
  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (_numbers.size() < 2) {
    throw std::logic_error("Not enough numbers to calculate a span");
  }
  int min = *std::min_element(_numbers.begin(), _numbers.end());
  int max = *std::max_element(_numbers.begin(), _numbers.end());
  return max - min;
}


void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  size_t distance = std::distance(begin, end);
  if (_numbers.size() + distance > N) {
    throw std::overflow_error("Adding range exceeds Span's capacity");
  }
  _numbers.insert(_numbers.end(), begin, end);
}