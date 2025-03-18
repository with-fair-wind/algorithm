#pragma once

namespace Algo_Sort
{
    template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
    void selectionSort(std::vector<T> &vec)
    {
        if (vec.empty() || vec.size() < 2)
            return;

        for (size_t i = 0; i < vec.size() - 1; ++i)
        {
            size_t minIndex = i;
            for (size_t j = i + 1; j < vec.size(); ++j)
            {
                if (vec[j] < vec[minIndex])
                    minIndex = j;
            }
            std::swap(vec[i], vec[minIndex]);
        }
    }

    template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
    void bubbleSort(std::vector<T> &vec)
    {
        if (vec.empty() || vec.size() < 2)
            return;

        for (size_t i = vec.size() - 1; i > 0; --i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                if (vec[j] > vec[j + 1])
                    std::swap(vec[j], vec[j + 1]);
            }
        }
    }

    template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
    void insertSort(std::vector<T> &vec)
    {
        if (vec.empty() || vec.size() < 2)
            return;

        for (size_t i = 1; i < vec.size(); ++i)
        {
            for (size_t j = i - 1; j >= 0 && vec[j] > vec[j + 1]; --j)
                std::swap(vec[j], vec[j + 1]);
        }
    }

    class Logarithm
    {
        PROPERTY_CREATE(int, rounds)
        PROPERTY_CREATE(int, maxSize)
        PROPERTY_CREATE(int, maxVal)

    private:
        template <typename T>
        using func = void (*)(std::vector<T> &vec);

    public:
        Logarithm();
        void randomVec(std::vector<int> &vec, int maxSize, int maxVal);
        void check(func<int> func1, func<int> func2);
    };
} // namespace Sort
