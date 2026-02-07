#include <iostream>
#include <vector>
#include "Count Subarrays Where Max Element Appears at Least K Times.h"
using namespace std;


int main() {
    Solution solution;

    vector<int> nums{1,3,2,3,3};
    int k = 2;

    long long ans = solution.countSubarrays(nums,k);
    cout << ans;

    return 0;
}