#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n,-1);
        long long s = 0; //
        for(int i = 0; i < n; i++) {
            s += nums[i]; // 入
            if (i < k * 2) {
                continue;
            }
            avgs[i - k] = s / (k * 2 + 1); // 注意是2k+1
            s -= nums[i - k * 2]; // 出
        }
        return avgs;
    }
};

//