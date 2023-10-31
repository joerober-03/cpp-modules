#include "iter.hpp"

int main()
{
    char a[] = {'A', 'B', 'C'};
    iter(a, 3, increment);
    int i[] = {1, 66, 93, 9};
    iter(i, 4, decrement);
    double d[] = {1.25, 6.6678, 3.14159, 0.1};
    iter(d, 4, increment);
    return 0;
}