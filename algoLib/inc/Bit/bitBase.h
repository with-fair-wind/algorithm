#pragma once

namespace Algo_BitSystem
{
    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    void printBinary(T num)
    {
        for (int i = sizeof(T) * CHAR_BIT - 1; i >= 0; --i)
            std::cout << ((num & (static_cast<T>(1) << i)) == 0 ? "0" : "1");
        std::cout << std::endl;
    }
}