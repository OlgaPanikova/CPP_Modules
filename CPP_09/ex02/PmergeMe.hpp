#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <set>
#include <ctime>

#include "JacobsthalGenerator.hpp"
#include "IndexManager.hpp"
#include "BoundedIndexGenerator.hpp"


class PmergeMe {
private:

public:
  PmergeMe();
  PmergeMe(const PmergeMe& copy);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();
  
  template <typename T>
  static bool CheckContainer(T &container);
  template <typename T>
  static bool IsContainerDuplicates(const T &container);
  template <typename T>
  static bool IsContainerSorted(const T &container);
  template <typename T>
  static bool checkSize(const T &container);
  template <typename T>
  void FordJonsonMerge(T &container);
  template <typename T>
  void BreakIntoPairs(const T &container, T &less, T &more);
  template <typename T>
  void BinarySorted(int element, T &container);
  template <typename T>
  int FindInsertPosition(const T &container, int size, int value);
  template <typename T>
  int checkEvenNumber(T &container);
  template <typename T>
  void recursiveSort(T &more);
  template <typename T>
  void insertUsingJacobsthal(T &less, T &more);

};

std::vector<int> createJacobsthalSequence(int count);

// struct JacobsthalGenerator {
//     int n2;
//     int n1;

//     JacobsthalGenerator() : n2(1), n1(1) {}

//     int nextNumber() {
//         int current = n1 + 2 * n2;
//         n2 = n1;
//         n1 = current;
//         return current;
//     }
// };

// // Структура для управления индексами Якобсталя
// struct IndexManager {
//     int upperBound;      // Текущая верхняя граница диапазона
//     int lowerBound;      // Текущая нижняя граница диапазона
//     int activeIndex;     // Текущий индекс
//     JacobsthalGenerator jacobGen;

//     IndexManager() : upperBound(1), lowerBound(0), activeIndex(1) {}

//     int nextIndex() {
//         int result = activeIndex;
//         activeIndex--;

//         if (activeIndex == lowerBound) {
//             lowerBound = upperBound;
//             upperBound = jacobGen.nextNumber();
//             activeIndex = upperBound;
//         }

//         return result - 1;
//     }
// };

// // Структура для ограничения диапазона индексов Якобсталя
// struct BoundedIndexGenerator {
//     IndexManager indexMgr;
//     int maxLimit; // Максимальный допустимый индекс

//     BoundedIndexGenerator(int limit) : maxLimit(limit) {}

//     int nextBoundedIndex() {
//         while (true) {
//             int index = indexMgr.nextIndex();
//             if (index < maxLimit) return index;
//         }
//     }
// };

template <typename T>
int PmergeMe::FindInsertPosition(const T &container, int size, int value) {
    int left = 0;
    int right = size - 1;
    typename T::const_iterator iter;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        iter = container.begin();
        std::advance(iter, mid);

        if (value < *iter) {
            right = mid - 1;
        } else if (value > *iter) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return left;
}

template <typename T>
void PmergeMe::BinarySorted(int element, T &container) {
    typename T::iterator insertPosition = container.begin();
    std::advance(insertPosition, FindInsertPosition(container, container.size(), element));
    container.insert(insertPosition, element);
}

template <typename T>
void PmergeMe::insertUsingJacobsthal(T &less, T &more) {
    std::vector<int> sequence = createJacobsthalSequence(less.size());
    for (size_t i = 0; i < sequence.size(); ++i) {
        int index = sequence[i];
        if (index < static_cast<int>(less.size())) {
            typename T::iterator it = less.begin();
            std::advance(it, index);
            BinarySorted(*it, more);
        }
    }
}

template <typename T>
void PmergeMe::recursiveSort(T &more) {
    if (more.size() <= 1) return;
    FordJonsonMerge(more);
}


template <typename T>
void PmergeMe::BreakIntoPairs(const T &container, T &min, T &max) {
    typename T::const_iterator it = container.begin();
    int half = container.size() / 2;

    for (int i = 0; i < half; ++i) {
        int a = *it++;
        int b = *it++;

        if (a < b) {
            min.push_back(a);
            max.push_back(b);
        } else {
            min.push_back(b);
            max.push_back(a);
        }
    }
}

template <typename T>
int PmergeMe::checkEvenNumber(T &container) {
    if (container.size() % 2 != 0) {
        int lastElement = container.back();
        container.pop_back();
        return lastElement;
    }
    return 0;
}

template <typename T>
void PmergeMe::FordJonsonMerge(T &container) {
    if (container.size() <= 1) return;
    int odd = checkEvenNumber(container);
    T less, more;
    BreakIntoPairs(container, less, more);
    recursiveSort(more);
    insertUsingJacobsthal(less, more);
    if (odd != 0) {
        BinarySorted(odd, more);
    }
    container = more;
}


template <typename T>
bool PmergeMe::checkSize(const T &container) {
    return container.size() > 3000;
}

template <typename T>
bool PmergeMe::IsContainerSorted(const T &container) {
    if (container.empty()) return true;
    typename T::const_iterator prev = container.begin();
    typename T::const_iterator curr = ++container.begin();
    while (curr != container.end()) {
        if (*prev > *curr) {
            return false;
        }
        ++prev;
        ++curr;
    }
    return true;
}

template <typename T>
bool PmergeMe::IsContainerDuplicates(const T &container) {
    typedef typename T::value_type ValueType;
    std::set<ValueType> uniqueElem;
    typename T::const_iterator i;
    for (i = container.begin(); i != container.end(); ++i) {
        if (!uniqueElem.insert(*i).second) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool PmergeMe::CheckContainer(T &container) {
    if (container.size() < 2) {
        std::cerr << "Error: The container must have at least two elements." << std::endl;
        return false;
    }
    if (IsContainerDuplicates(container)) {
        std::cerr << "Error: The container contains duplicate elements." << std::endl;
        return false;
    }
    if (IsContainerSorted(container)) {
        std::cerr << "Error: The container is already sorted." << std::endl;
        return false;
    }
    if (checkSize(container)) {
        std::cerr << "Error: The container size exceeds the maximum allowed size of 3000." << std::endl;
        return false;
    }
    return true;
}


#endif