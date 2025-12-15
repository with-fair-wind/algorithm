#include <Demo/demo_sort.h>

namespace Demo_Sort {
struct X {
    int val = 42;
    bool operator<(const X& other) const { return val < other.val; }
};

std::ostream& operator<<(std::ostream& os, const X& x) {
    os << x.val;
    return os;
}

void demo_v1() {
    std::vector<int> vec{2, 3, 4, 2, 6, 1};
    Algo_Sort::insertSort(vec);
    Algo_Utility::Utility::printVec(vec);

    std::vector<X> vecx{X{2}, X{1}, X{3}, X{5}, X{2}};
    Algo_Sort::selectionSort(vecx);
    Algo_Utility::Utility::printVec(vecx);
}

void demo_v2() {
    Algo_Sort::Logarithm logarithm;
    logarithm.check(Algo_Sort::selectionSort, Algo_Sort::bubbleSort);
}
}  // namespace Demo_Sort