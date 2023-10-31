#include <iostream>

int main(int argc, char **argv)
{
    int i = 0;

    if (!argv[1])
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (++i < argc)
        {
            int j = -1;
            while (argv[i][++j] != '\0')
                std::cout << (char)toupper(argv[i][j]);
            if (i < argc -1)
                std::cout << " ";
        }
        
        std::cout << std::endl;
    }
    return (0);
}