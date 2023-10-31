#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <list>
#include <unistd.h>
#include <sys/time.h>

class PmergeMe
{
    private:

    std::list<int> list;
    std::vector<int> vector;
    long int checkms1;
    long int checkms2;

    void    setList(int index, int i);
    int     getList(int index);
    void    vectorMergeInsertionSort(int left, int right, int subnum);
    void    vectorInsertionSort(int left, int right);
    void    vectorMergeSort(int left, int middle, int right);
    void    listMergeInsertionSort(int left, int right, int subnum);
    void    listInsertionSort(int left, int right);
    void    listMergeSort(int left, int middle, int right);

    public:

    PmergeMe(void);
    //PmergeMe(const std::string argv);
    PmergeMe(const PmergeMe &rhs);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe(void);

    bool    checkErrors(char **args, const int num, int i);
    void    initSort(void);

    void    setCheckms(long int value, int i);
};