#include "Two Sum.h"
using namespace std;
#include <vector>
#include <iostream>

int main() {
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = solution.twoSum(nums, target);
    // 输出结果
    for (int index : result) {
        cout << index << " ";
    }
    return 0;
}
