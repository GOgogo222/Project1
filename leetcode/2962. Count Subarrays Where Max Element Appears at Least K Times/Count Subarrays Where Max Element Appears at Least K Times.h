#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int left = 0,cnt = 0;
        long long ans = 0;

        for (int x : nums) {
            cnt += x == mx;
            while (cnt >= k) { // 从0,1...到left-1
                cnt -= x == nums[left];
                left++;
            }
            ans += left;
        }
        return ans;        
    }
};

//思路：这题相较于上一道题的难度在于
//干脆搞一个set容器让其自动排序，且没有重复元素
//求最大值得了。。。
