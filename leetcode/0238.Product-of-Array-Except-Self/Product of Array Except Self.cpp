#include "Product of Array Except Self.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.productExceptSelf(nums);
    for(auto num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}