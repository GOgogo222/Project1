#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size(); // 记录数组长

        //前缀积
        vector<int> L(length,0); // 函数构造(长度,初始元素)
        //后缀积
        vector<int> R(length,0);

        L[0] = 1;
        for(int i = 1; i < length; ++i)
        {
            L[i] = nums[i-1] * L[i-1]; // 精华所在
        }

        R[length-1] = 1;
        for(int i = length-2; i >= 0 ; --i)
        {
            R[i] = nums[i+1] * R[i+1];
        }

        for(int i = 0; i < length; ++i)
        {
            nums[i] = R[i] * L[i];
        }


        return nums;
    }
};

//思路：先把所有的元素乘起来，然后再一个个地除
//这样时间O(n),空间O(n)
//但是遇到0元素不好处理，而且题目要求不要使用除法 :)

//方法一：前缀×后缀
//三个for循环，两个数组
//分别找到每个元素的前缀积和后缀积(O(n+n))存储到等长的数组中,然后数组元素一一对应相(O(n))
//时间复杂度O(n),空间复杂度O(n)