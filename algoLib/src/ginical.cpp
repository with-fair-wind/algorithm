#include <GiniCal/ginical.h>

namespace Algo_GiniCal {
void experiment(int nums, int rounds) {
    std::vector<double> wealth(nums, 100.0);
    std::vector<bool> hasMoney(nums, false);
    std::srand(std::time(nullptr));

    for (int i = 0; i < rounds; i++) {
        for (int j = 0; j < nums; j++)
            if (wealth[j] > 0) hasMoney[j] = true;

        for (int j = 0; j < nums; j++) {
            if (hasMoney[j]) {
                int other = j;
                do {
                    other = rand() % nums;
                } while (other == j);
                wealth[j]--;
                wealth[other]++;
            }
        }
    }

    std::sort(wealth.begin(), wealth.end());
    std::cout << "列出每个人的财富(贫穷到富有) : " << std::endl;
    for (int i = 0; i < nums; i++) {
        std::cout << static_cast<int>(wealth[i]) << " ";
        if (i % 10 == 9) std::cout << std::endl;
    }
    std::cout << "\n这个社会的基尼系数为 : " << calculateGini(wealth) << std::endl;
}

double calculateGini(const std::vector<double>& wealth) {
    double sumOfAbsoluteDifferences = 0.0;
    double sumOfWealth = 0.0;
    size_t n = wealth.size();
    for (size_t i = 0; i < wealth.size(); i++) {
        sumOfWealth += wealth[i];
        for (size_t j = 0; j < wealth.size(); j++) sumOfAbsoluteDifferences += std::abs(wealth[i] - wealth[j]);
    }
    return sumOfAbsoluteDifferences / (2 * n * sumOfWealth);
}
}  // namespace Algo_GiniCal
