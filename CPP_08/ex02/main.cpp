#include "MutantStack.hpp"

#include <string>
#include "MutantStack.hpp"

int main() {
    {
        std::cout << "Test 1: Basic Operations\n";
        MutantStack<int> MutStack;
        MutStack.push(21);
        MutStack.push(42);
        std::cout << "Top: " << MutStack.top() << std::endl;
        MutStack.pop();
        std::cout << "Size: " << MutStack.size() << std::endl;

        MutStack.push(1);
        MutStack.push(7);
        MutStack.push(999);
        MutStack.push(0);

        std::cout << "Elements (using iterators): ";
        for (MutantStack<int>::iterator it = MutStack.begin(); it != MutStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }

    {
        std::cout << "\nTest 2: Copy and Traversal\n";
        MutantStack<int> mystack;
        mystack.push(3);
        mystack.push(2);
        mystack.push(1);

        MutantStack<int> stk(mystack);
        std::cout << "Top of copied stack: " << stk.top() << std::endl;

        std::cout << "Forward traversal: ";
        for (MutantStack<int>::const_iterator it = mystack.begin(); it != mystack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";

        std::cout << "Reverse traversal: ";
        for (MutantStack<int>::reverse_iterator rit = mystack.rbegin(); rit != mystack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << "\n";
    }

    {
        std::cout << "\nTest 3: Other Data Types\n";
        MutantStack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");

        for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
