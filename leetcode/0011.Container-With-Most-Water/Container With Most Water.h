#include <vector>
#include <algorithm>
using namespace std;


//法一：暴力法
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 两个for循环，枚举所有可能的容器组合，计算面积并更新最大值



// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 法二：双指针法
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1) return 0;
        
        int i,j; // 两个指针
        int n = height.size();
        i = 0; j = n-1; // 分别指向数组两端
        int ans = 0; // 最终答案(answer)
        while(i < j)
        {
            int area = min(height[i],height[j]) * (j - i); // 面积的计算
            ans = max(ans,area); // 比较得出最终答案
            if(height[i] < height[j]) i++;
            else j--; // 判断元素的长度
        }
        return ans;
    }
};

//思路：移动高较小的那个指针，看面积是否可能增大

//不加这一行，执行时间0ms!!!
//if(height.size() == 0 || height.size() == 1) return 0;

//小细节：min(height[i],height[j]) * (j - i) 学会用max和min函数