#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    int i;
    std::string lineRead;

    if (argc != 4)
    {
        std::cout << "missing an argument; format: ./exe <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string outFileName(argv[1]);
    std::ifstream infile;
    infile.open(argv[1]);
    if (infile.fail())
    {
        std::cout << "the file " << argv[1] << " cannot be opened or does not exists." << std::endl;
        return (1);
    }
    std::ofstream outfile;
    outfile.open(outFileName.append(".replace"));
    if (outfile.fail())
    {
        std::cout << "error opening outfile" << std::endl;
        return (1);
    }
    getline (infile, lineRead);
    while (!infile.eof())
    {
        i = -1;
        while (lineRead[++i] != '\0')
        {
            if (lineRead.compare(i, strlen(argv[2]), argv[2]) == 0)
            {
                outfile << argv[3];
                i += (strlen(argv[2]) - 1);
            }
            else
                outfile << lineRead[i];
        }
        outfile << std::endl;
        getline (infile, lineRead);
    }
    outfile.close();
    infile.close();
    return (0);
}