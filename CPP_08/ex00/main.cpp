#include "easyfind.hpp"

int main() {
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

  try {
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;

        std::cout << "Found: " << *easyfind(lst, 20) << std::endl;

        std::cout << "Found: " << *easyfind(deq, 300) << std::endl;

        std::cout << "Found: " << *easyfind(vec, 42) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}