#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     int maxVowels(string s, int k) {
//         int sum = 0;
//         int max = 0;
//         int right = 0;
//         while(right < s.length()) {
//             sum += isYuan(s[right]); // 增
//             right++;
//             if(right >= k) {
//                 max = std::max(max,sum);
//                 sum -= isYuan(s[right-k]); // 删：窗口左端点为 right−k+1，删除第right-k个即可
//             }
//         }
//         return max;
//     }

// public:
//     bool isYuan(char s) {
//         return s=='a' ||s=='e' ||s=='i' ||s=='o' ||s=='u' ? 1 : 0;
//     }
// };


// 解法二
// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 这是定长滑窗的基本套路

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0,vowel = 0;
        for (int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                vowel++;
            }

            int left = i - k + 1;
            if (left < 0) {
                continue; // 尚未形成窗口
            }

            ans = max(ans,vowel);

            char out = s[left];
            if(isVowel(out)) {
                vowel--;
            }
        }
        return ans;
    }

public:
    bool isVowel(char s) {
        return s=='a' ||s=='e' ||s=='i' ||s=='o' ||s=='u' ? 1 : 0;
    }
};