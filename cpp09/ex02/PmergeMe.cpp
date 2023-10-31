#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    this->list = rhs.list;
    this->vector = rhs.vector;
    this->checkms1 = rhs.checkms1;
    this->checkms2 = rhs.checkms2;
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
}

bool    PmergeMe::checkErrors(char **args, const int num, int i)
{
    int j = 0;

    while (++j < num)
    { 
        std::string input(args[j]);
        if (input.empty())
        {
            std::cerr << "input is empty !" << std::endl;
            return (false);
        }
        for (unsigned long i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                std::cerr << "invalid character in string !" << std::endl;
                return (false);
            }
        }
        if (input[0] != 0)
        {
            try
            {
                if (i == 0)
                    this->vector.push_back(stoi(input));
                else
                    this->list.push_back(stoi(input));
            }
            catch (...)
            {
                std::cerr << "out of range number in string !" << std::endl;
                return (false);
            }
        }
    }
    return (true);
}

void    PmergeMe::initSort(void)
{
    //listMergeInsertionSort(0, this->list.size() - 1, 2);
    //std::list<int>::iterator it = this->list.begin();
    //std::list<int>::iterator ite = this->list.end();
    //while (it != ite)
    //{
    //    std::cout << *it << " ";
    //    it++;
    //}
    //std::cout << std::endl;
    std::vector<int> og = this->vector;
    std::list<int> og2 = this->list;
    struct timeval diff1, diff2, start1, end1, start2, end2;
    gettimeofday(&start1, NULL);
    vectorMergeInsertionSort(0, this->vector.size() - 1, 2);
    gettimeofday(&end1, NULL);
    gettimeofday(&start2, NULL);
    listMergeInsertionSort(0, this->vector.size() - 1, 2);
    gettimeofday(&end2, NULL);
    std::cout << "Before: ";
    for (unsigned long i = 0; i < og.size(); i++)
        std::cout << og[i] << " ";
    std::cout << std::endl;
    std::cout << "After:  ";
    for (unsigned long i = 0; i < this->vector.size(); i++)
        std::cout << this->vector[i] << " ";
    std::cout << std::endl;
    timersub(&end1, &start1, &diff1);
    timersub(&end2, &start2, &diff2);
    long int ms = diff1.tv_sec * 1000000 + diff1.tv_usec;
    long int ms2 = diff2.tv_sec * 1000000 + diff2.tv_usec;
    ms += this->checkms1;
    ms2 += this->checkms2;
    std::cout << std::fixed << "Time to process a range of " << this->vector.size() << " elements with std::vector : " << ms << " us" <<std::endl;
    std::cout << std::fixed << "Time to process a range of " << this->list.size() << " elements with std::list : " << ms2 << " us" <<std::endl;
}

void    PmergeMe::vectorMergeInsertionSort(int left, int right, int subnum)
{
    if (right - left + 1 <= subnum)
        vectorInsertionSort(left, right);
    else
    {
        int middle = left + (right - left) / 2;
        vectorMergeInsertionSort(left, middle, subnum);
        vectorMergeInsertionSort(middle + 1, right, subnum);
        vectorMergeSort(left, middle, right);
    }
}

void    PmergeMe::vectorInsertionSort(int left, int right)
{
    int key;
    int j;
    
    for (int i = left + 1; i <= right; i++)
    {
        key = this->vector[i];
        j = i - 1;

        while (j >= left && this->vector[j] > key)
        {
            this->vector[j + 1] = this->vector[j];
            j--;
        }
        this->vector[j + 1] = key;
    }
}

void    PmergeMe::vectorMergeSort(int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = this->vector[left + i];
    for (j = 0; j < n2; j++)
        R[j] = this->vector[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            this->vector[k] = L[i];
            i++;
        }
        else
        {
            this->vector[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        this->vector[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        this->vector[k] = R[j];
        j++;
        k++;
    }
}

void    PmergeMe::listMergeInsertionSort(int left, int right, int subnum)
{
    if (right - left + 1 <= subnum)
        listInsertionSort(left, right);
    else
    {
        int middle = left + (right - left) / 2;
        listMergeInsertionSort(left, middle, subnum);
        listMergeInsertionSort(middle + 1, right, subnum);
        listMergeSort(left, middle, right);
    }
}

void    PmergeMe::listInsertionSort(int left, int right)
{
    int key;
    int j;
    
    for (int i = left + 1; i <= right; i++)
    {
        key = this->getList(i);
        j = i - 1;

        while (j >= left && this->getList(j) > key)
        {
            this->setList(j + 1, this->getList(j));
            j--;
        }
        this->setList(j + 1, key);
    }
}

void    PmergeMe::listMergeSort(int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = this->getList(left + i);
    for (j = 0; j < n2; j++)
        R[j] = this->getList(middle + 1 + j);
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            this->setList(k, L[i]);
            i++;
        }
        else
        {
            this->setList(k, R[j]);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        this->setList(k, L[i]);
        i++;
        k++;
    }
    while (j < n2)
    {
        this->setList(k, R[j]);
        j++;
        k++;
    }
}

void    PmergeMe::setList(int index, int i)
{
    std::list<int>::iterator it = this->list.begin();
    for (int j = 0; j < index; j++)
        it++;
    *it = i;
}

int    PmergeMe::getList(int index)
{
    std::list<int>::iterator it = this->list.begin();
    for (int j = 0; j < index; j++)
        it++;
    return (*it);
}

void    PmergeMe::setCheckms(long int value, int i)
{
    if (i == 0)
        this->checkms1 = value;
    else
        this->checkms2 = value;
}