#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "-------------MutantStack-------------" << std::endl;
        MutantStack<int> mstack;
        if (mstack.empty())
            std::cout << "mstack is empty" << std::endl;
        mstack.push(5);
        mstack.push(17);
        std::cout << "element on top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size of the MutantStack: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(1);
        mstack.push(-65);
        mstack.push(727);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "content of the MutantStack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        MutantStack<int>::reverse_iterator it2 = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite2 = mstack.rend();
        std::cout << "content of the MutantStack(reverse):" << std::endl;
        while (it2 != ite2)
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
        if (mstack.empty())
            std::cout << "mstack is empty" << std::endl;
        std::cout << "-------------Stack Copy-------------" << std::endl;
        std::stack<int> s(mstack);
        s.pop();
        std::cout << "element on top: " << s.top() << std::endl;
    }
    std::cout << "----------------List----------------" << std::endl;
    {
        std::list<int> mlist;
        if (mlist.empty())
            std::cout << "lstack is empty" << std::endl;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << "element on top: " << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << "size of the list: " << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(1);
        mlist.push_back(-65);
        mlist.push_back(727);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        std::cout << "content of the list:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int>::reverse_iterator it2 = mlist.rbegin();
        std::list<int>::reverse_iterator ite2 = mlist.rend();
        std::cout << "content of the MutantStack(reverse):" << std::endl;
        while (it2 != ite2)
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
        if (mlist.empty())
            std::cout << "lstack is empty" << std::endl;
    }
    return 0;
}