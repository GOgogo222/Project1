#include <iostream>
#include <vector>
#include "Rotate Array.h"

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums, k);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}