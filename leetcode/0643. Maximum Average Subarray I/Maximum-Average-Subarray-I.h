#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        int sum = 0;
        int maxSum = INT_MIN; // 负无穷
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int left = i - k + 1;
            if(i < k - 1) { 
                continue; // 未形成窗口
            }

            maxSum = max(maxSum,sum);
            sum -= nums[left];
        }
        return (double) maxSum / k; // 注意这个强制类型转换的写法
    }
};

//思路：求定长子数组的最大平均值也是求最大和
//k值按理来说是不能大于数组的长度的
//搞错了一个if的判定

