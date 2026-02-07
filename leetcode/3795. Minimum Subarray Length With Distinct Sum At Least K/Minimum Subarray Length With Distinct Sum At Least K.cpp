#include <iostream>
#include <vector>
#include "Minimum Subarray Length With Distinct Sum At Least K.h"
using namespace std;

int main() {
    Solution solution;
 // nums = [2,2,3,1], k = 4
    vector<int> nums {2,2,3,1};
    int k = 4;

    int ans;

    ans = solution.minLength(nums,k);

    cout << ans;

    return 0;
}