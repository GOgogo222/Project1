#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n); // 指定空间构造
        for(int i = 0; i < n; ++i)
        {
            newArr[(i+k)%n] = nums[i]; // 由于已经指定好空间大小
        }
        nums = newArr;
    }
};

//方法一：公式法
//newArr[(i+k)%n] = nums[i];
//时间复杂度：O(n)
//空间复杂度：O(n)


// class Solution {
// public:
//     void reverse(vector<int>& nums, int start, int end) {
//         while (start < end) {
//             swap(nums[start], nums[end]); // 交换（swap）位置
//             start += 1;
//             end -= 1;
//         }
//     }

//     void rotate(vector<int>& nums, int k) {
//         k %= nums.size(); 
//         reverse(nums, 0, nums.size() - 1);
//         reverse(nums, 0, k - 1);
//         reverse(nums, k, nums.size() - 1);
//     }
// };

//方法二：翻转（reverse）三次数组
//时间复杂度：O(n)  
//空间复杂度：O(1)