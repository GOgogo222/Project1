#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum,cur_sum; // max sum,current sum
        cur_sum = max_sum = nums[0]; // 之前和初始化
        for (int i = 1; i < nums.size(); i++)
        {
            cur_sum = max(nums[i],cur_sum + nums[i]);
            max_sum = max(cur_sum,max_sum);
        }
        return max_sum;
    }
}; 

//题解：
//方法一：贪心
//若当前指针所指元素之前的和小于0，则丢弃**当前元素之前**的序列
