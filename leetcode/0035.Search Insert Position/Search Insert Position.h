#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // 左右指针
        while(left <= right) { // 注意
            int mid = left + (right - left) / 2; // 安全写法
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return left;
    }
};

//思路：简单之处在于每个元素都是唯一的，标准的二分查找法求解