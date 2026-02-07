#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // 外层循环遍历每个元素（索引i）
        for (int i = 0; i < nums.size(); i++) {
            // 内层循环遍历i之后的所有元素（索引j）
            for (int j = i + 1; j < nums.size(); j++) {
                // 检查两数之和是否等于目标值
                if (nums[i] + nums[j] == target) {
                    return {i, j};  // 找到解，立即返回
                }
            }
        }
        return {};  // 题目保证有解，此句实际不会执行
    }
};

