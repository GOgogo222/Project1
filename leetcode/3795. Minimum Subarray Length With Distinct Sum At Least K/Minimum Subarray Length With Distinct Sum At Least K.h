#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength (vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int left = 0, ans = INT_MAX,sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //入
            int x = nums[i];
            cnt[x]++;
            if (cnt[x] == 1) {
                sum += nums[i];
            }

            while (sum >= k) {
                //更新
                ans = min(ans,i - left + 1);
                //出
                int out = nums[left];
                cnt[out]--;
                if (cnt[out] == 0) {
                    sum -= nums[left];
                }

                left++; // pay attention!!!
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};