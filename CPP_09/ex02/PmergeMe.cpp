#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this =  copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe() {}

// Функция для создания последовательности индексов Якобсталя
std::vector<int> createJacobsthalSequence(int count) {
    BoundedIndexGenerator boundedGen(count);
    std::vector<int> sequence;

    for (int i = 0; i < count; ++i) {
        sequence.push_back(boundedGen.nextBoundedIndex());
    }

    return sequence;
}