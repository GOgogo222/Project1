#include <iostream>
#include "K Radius Subarray Averages.h"
#include <vector>

int main() {
    Solution solution;
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    vector<int> result = solution.getAverages(nums, k);
    for (int avg : result) {
        std::cout << avg << " ";
    }
    std::cout << std::endl;
    return 0;
}