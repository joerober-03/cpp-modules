#include "Array.hpp"

int main()
{
    try
    {
        Array<int> array(7);
        std::cout << array.size() << std::endl;
        for (int i = 0; i < 7; i++)
            array[i] = i;
        std::cout << array[5] << std::endl;
        Array<int> array2(array);
        array2[5] = 42;
        std::cout << array2[5] << std::endl;
        std::cout << array[5] << std::endl;
        std::cout << array[9] << std::endl;
    }
    catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
    try
    {
        Array<char> array(12);
        std::cout << array.size() << std::endl;
        for (int i = 0; i < 12; i++)
            array[i] = 97 + i;
        std::cout << array[2] << std::endl;
        std::cout << array[11] << std::endl;
        std::cout << array[12] << std::endl;
    }
    catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}