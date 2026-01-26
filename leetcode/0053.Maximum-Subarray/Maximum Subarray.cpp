#include <iostream>
#include <vector>
#include "Maximum Subarray.h"
using namespace std;

int main()
{
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = s.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}
