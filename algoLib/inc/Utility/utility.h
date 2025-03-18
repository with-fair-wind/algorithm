#pragma once

namespace Algo_Utility
{
    class Utility
    {
    public:
        template <typename T>
            requires requires { std::cout << std::declval<T>(); }
        static void printVec(const std::vector<T> &vec)
        {
            for (const auto &cur : vec)
                std::cout << cur << " ";
            std::cout << "\n";
        }
    };
} // namespace Algo_Utility
