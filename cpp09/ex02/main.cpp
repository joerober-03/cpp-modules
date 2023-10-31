#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "PmergeMe needs a list of numbers to sort !" << std::endl;
        return (1);
    }
    PmergeMe pmm;
    struct timeval diff1, diff2, start1, end1, start2, end2;
    gettimeofday(&start1, NULL);
    if (pmm.checkErrors(argv, argc, 0) == false)
        return (2);
    gettimeofday(&end1, NULL);
    gettimeofday(&start2, NULL);
    if (pmm.checkErrors(argv, argc, 2) == false)
        return (2);
    gettimeofday(&end2, NULL);
    timersub(&end1, &start1, &diff1);
    timersub(&end2, &start2, &diff2);
    long int ms = diff1.tv_sec * 1000000 + diff1.tv_usec;
    long int ms2 = diff2.tv_sec * 1000000 + diff2.tv_usec;
    pmm.setCheckms(ms, 0);
    pmm.setCheckms(ms2, 1);
    pmm.initSort();
    return 0;
}