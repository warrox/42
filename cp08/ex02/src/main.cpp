#include "../includes/mutantstack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements in stack: " << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "Elements in reverse order: " << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    const MutantStack<int> const_mstack = mstack;
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    std::cout << "Const iterator elements: " << std::endl;
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    MutantStack<int> copied_stack(mstack);
    std::cout << "Copied stack elements: " << std::endl;
    MutantStack<int>::iterator copied_it = copied_stack.begin();
    MutantStack<int>::iterator copied_ite = copied_stack.end();
    while (copied_it != copied_ite)
    {
        std::cout << *copied_it << " ";
        ++copied_it;
    }
    std::cout << std::endl;

    MutantStack<int> assigned_stack;
    assigned_stack = mstack;
    std::cout << "Assigned stack elements: " << std::endl;
    MutantStack<int>::iterator assigned_it = assigned_stack.begin();
    MutantStack<int>::iterator assigned_ite = assigned_stack.end();
    while (assigned_it != assigned_ite)
    {
        std::cout << *assigned_it << " ";
        ++assigned_it;
    }
    std::cout << std::endl;

    MutantStack<int> empty_stack;
    std::cout << "Testing empty stack: " << std::endl;
    if (empty_stack.begin() == empty_stack.end())
    {
        std::cout << "Stack is empty." << std::endl;
    }

    return 0;
}
