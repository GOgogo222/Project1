#include <vector>

// 方法一:
// 时间复杂度O(n)，空间复杂度O(n)
// 使用了辅助空间
// class Solution {
// public:
//     void moveZeroes(std::vector<int>& nums) { 
//         int n = nums.size();
//         int j = 0;
//         std::vector<int> nums2(n,0);
//         for(int i = 0; i < n; i++) {
//             if(nums[i] != 0) {
//                 nums2[j] = nums[i];
//                 //nums.erase(nums.begin() + i);
//                 //nums.push_back(0);
//                 j++;
//             }
//         }
//         nums = nums2;
//     }
// };

// 思路一：遍历数组，有0就删，然后再push_back一个0
// 左边一直在删，右边一直在push?看起来像死循环
// 思路二：提前构造n个0的数组，采用赋值而不是push的方式


// 方法二:
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) {
            return;
        }
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0 ) {
                if(i > j) {
                 nums[j] = nums[i];
                 nums[i] = 0; //等同于一次交换
                }
              j++;
            }
        }
    }
};

//i>j就是为了避免i==j时发生交换
//用赋值而不是交换的方式，理论上更节省时间
//一个小细节：要判断数组的大小是否为空



