#include <GiniCal/experiment.h>

namespace GiniCal
{
    void experiment(int n, int t)
    {
        std::vector<double> wealth(n, 100.0);
        std::vector<bool> hasMoney(n, false);
        std::srand(std::time(nullptr));

        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (wealth[j] > 0)
                    hasMoney[j] = true;
            }
            for (int j = 0; j < n; j++)
            {
                int other = j;
                do
                {
                    other = rand() % n;
                } while (other == j);
                wealth[j]--;
                wealth[other]++;
            }
        }

        std::sort(wealth.begin(), wealth.end());
        std::cout << "列出每个人的财富(贫穷到富有) : " << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout << static_cast<int>(wealth[i]) << " ";
            if (i % 10 == 9)
            {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
        std::cout << "这个社会的基尼系数为 : " << calculateGini(wealth) << std::endl;
    }

    double calculateGini(const std::vector<double> &wealth)
    {
        double sumOfAbsoluteDifferences = 0.0;
        double sumOfWealth = 0.0;
        int n = wealth.size();
        for (size_t i = 0; i < wealth.size(); i++)
        {
            sumOfWealth += wealth[i];
            for (size_t j = 0; j < wealth.size(); j++)
                sumOfAbsoluteDifferences += std::abs(wealth[i] - wealth[j]);
        }
        return sumOfAbsoluteDifferences / (2 * n * sumOfWealth);
    }
} // namespace
