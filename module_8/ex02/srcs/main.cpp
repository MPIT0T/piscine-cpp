#include "MutantStack.hpp"
#include <iostream>
#include <list>

void printHeader(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    // Subject test
    {
        printHeader("Subject Test with MutantStack");
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        std::cout << "Iterating MutantStack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }

    // Comparison with std::list
    {
        printHeader("Comparison with std::list");
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << "Back: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "Size after pop_back: " << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;

        std::cout << "Iterating std::list:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    // Test copy constructor and assignment
    {
        printHeader("Copy Constructor / Assignment Test");
        MutantStack<std::string> original;
        original.push("hello");
        original.push("world");

        MutantStack<std::string> copy(original);
        MutantStack<std::string> assigned;
        assigned = original;

        std::cout << "Original top: " << original.top() << std::endl;
        std::cout << "Copy top: " << copy.top() << std::endl;
        std::cout << "Assigned top: " << assigned.top() << std::endl;
    }

    // Test iterator const correctness (if implemented)
    {
        printHeader("Const Iterator Test");
        MutantStack<int> stack;
        for (int i = 0; i < 5; ++i)
            stack.push(i * 10);

        MutantStack<int>::const_iterator cit = stack.begin();
        std::cout << "First const-iterated value: " << *cit << std::endl;
    }

    return 0;
}
