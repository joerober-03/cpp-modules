#include "easyfind.hpp"

int main()
{
    try
    {
        std::list<int> lst;
        lst.push_back(7);
        lst.push_back(9);
        lst.push_back(2);
        lst.push_back(6);
        lst.push_back(5);
        lst.push_back(8);
        lst.push_back(-2);
        lst.push_back(1);
        easyfind(lst, -9);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::vector<int> vct;
        vct.push_back(7);
        vct.push_back(9);
        vct.push_back(2);
        vct.push_back(6);
        vct.push_back(5);
        vct.push_back(8);
        vct.push_back(-2);
        vct.push_back(1);
        easyfind(vct, -2);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::deque<int> dqe;
        dqe.push_back(-1);
        dqe.push_back(-9);
        dqe.push_back(-2);
        dqe.push_back(-6);
        dqe.push_back(-5);
        dqe.push_back(-8);
        dqe.push_back(-10);
        dqe.push_back(-19);
        dqe.push_back(-14);
        dqe.push_back(-90);
        dqe.push_back(-24);
        dqe.push_back(-2);
        dqe.push_back(-58);
        dqe.push_back(-85);
        dqe.push_back(-24);
        dqe.push_back(-11);
        easyfind(dqe, -24);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}