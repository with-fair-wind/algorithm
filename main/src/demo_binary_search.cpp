#include <Demo/demo_binary_search.h>

namespace Demo_BinarySearch
{
    void demo_v1()
    {
        std::vector<int> vec{1, 2, 2, 5, 6, 8, 10, 14, 17, 23};
        std::cout << "find num in sorted vector:  " << std::boolalpha << Algo_BinarySearch::findNum(vec, 3) << std::endl;
        std::cout << "find >= num most left index: " << Algo_BinarySearch::findLeft(vec, 2) << std::endl;
        std::cout << "find <= num most right index: " << Algo_BinarySearch::findRight(vec, 4) << std::endl;

        vec = {1, 3, 4, 6, 2, 4, 5, 7, 2};
        std::cout << "find peak element index: " << Algo_BinarySearch::findPeakElement(vec) << std::endl;
    }
} // namespace Demo_BinarySearch