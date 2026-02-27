#include "PmergeMe.hpp"

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         std::cerr << "Error" << std::endl;
//         return 1;
//     }

//     PmergeMe sorter;
//     sorter.process(argv);

//     return 0;
// }

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try
    {
        sorter.process(argv);
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}