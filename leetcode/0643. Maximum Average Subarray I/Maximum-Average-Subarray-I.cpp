#include "Maximum-Average-Subarray-I.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution solution;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double result = solution.findMaxAverage(nums, k);
    cout << "The maximum average of subarrays of length " << k << " is: " << result << endl;
    return 0;
}