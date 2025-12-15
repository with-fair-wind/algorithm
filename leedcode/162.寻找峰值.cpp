/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int findPeakElement(vector<int>& vec) {
        if (vec.empty()) return -1;
        if (vec.size() == 1) return 0;
        if (vec[0] > vec[1]) return 0;
        if (vec[vec.size() - 2] < vec[vec.size() - 1]) return vec.size() - 1;
        int L = 1, R = vec.size() - 2, res = -1;
        while (L <= R) {
            int mid = L + ((R - L) >> 1);
            if (vec[mid - 1] > vec[mid])
                R = mid - 1;
            else if (vec[mid + 1] > vec[mid])
                L = mid + 1;
            else {
                res = mid;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
