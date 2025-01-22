#include <Sort/sort.h>

namespace Algo_Sort
{
    Logarithm::Logarithm()
    {
        m_rounds = 100000;
        m_maxSize = 10;
        m_maxVal = 100;
    }

    void Logarithm::randomVec(std::vector<int> &vec, int maxSize, int maxVal)
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, maxSize);

        vec.resize(distribution(generator));

        distribution = std::uniform_int_distribution<int>(-maxVal, maxVal);
        for (auto &cur : vec)
            cur = distribution(generator);
    }

    void Logarithm::check(func<int> func1, func<int> func2)
    {
        bool success = true;
        for (int i = 0; i < m_rounds; ++i)
        {
            std::vector<int> ori;
            randomVec(ori, m_maxSize, m_maxVal);
            std::vector<int> vec1 = ori;
            std::vector<int> vec2 = ori;

            func1(vec1);
            func2(vec2);

            for (size_t i = 0; i < vec1.size(); ++i)
            {
                if (vec1[i] != vec2[i])
                {
                    success = false;
                    break;
                }
            }

            if (!success)
            {
                std::cout << "Failure Use Case: \n ";
                printVec(ori);
                printVec(vec1);
                printVec(vec2);
                return;
            }
        }
        std::cout << "Pass!\n";
    }
} // namespace Sort