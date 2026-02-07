#include "Search Insert Position.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = solution.searchInsert(nums, target);
    cout << "Array: ";
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "The target " << target << " is at index: " << result << endl;

    return 0;
}