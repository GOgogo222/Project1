#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int max_sum,cur_sum; // max sum,current sum
//         cur_sum = max_sum = nums[0]; // 之前和初始化
//         for (int i = 1; i < nums.size(); i++)
//         {
//             cur_sum = max(nums[i],cur_sum + nums[i]);
//             max_sum = max(cur_sum,max_sum);
//         }
//         return max_sum;
//     }
// }; 

//题解：
//方法一：贪心
//若当前指针所指元素之前的和小于0，则丢弃**当前元素之前**的序列

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

//方法二：动态规划
//一个max函数，用来决定是将当前元素加入之前的子数组，还是从当前的pre开始重新计数
//maxAns记录全局最大子数组和
