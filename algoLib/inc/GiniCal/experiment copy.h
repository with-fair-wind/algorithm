#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace GiniCal
{
    void experiment(int n, int t);
    double calculateGini(const std::vector<double> &wealth);
} // namespace GiniCal
