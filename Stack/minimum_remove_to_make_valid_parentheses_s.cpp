// 1249. 移除无效的括号
// 时间：O(n)
//分析：左右指针遍历法，可惜了，解决不了类似于"())()((("->"()()"这样的问题；

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left <= right) { // 左指针小于等于右指针！
            // 左指针：跳过非括号字符
            if (s[left] != '(' && s[left] != ')') {
                left++;
                continue;
            }
            
            // 右指针：跳过非括号字符
            if (s[right] != '(' && s[right] != ')') {
                right--;
                continue;
            }
            
            // 如果左指针遇到右括号，删除它
            if (s[left] == ')') {
                s.erase(s.begin() + left);
                right--; // 字符串长度减少，右边界前移
                continue;
            }
            
            // 如果右指针遇到左括号，删除它
            if (s[right] == '(') {
                s.erase(s.begin() + right);
                right--; // 字符串长度减少，右边界前移
                continue;
            }
            
            // 如果左指针遇到左括号且右指针遇到右括号，匹配成功
            if (s[left] == '(' && s[right] == ')') {
                left++;
                right--;
                continue;
            }
        }
        
        return s;
    }
};


// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         //1.怎么检测无效？
//         //2.怎么处理无效？
//         //两个存储所有括号的栈同时弹出元素，他们存储的数据是逆序的；但是这样不好复原原来的字符串了；
//         //可以从头尾两边开始遍历！
//         string t;
//         int i = 0,j = s.size()-1;
//         int n = s.size();  //保留初始参数
//         for(; i < s.size(), j > 0;) { //偶数无法相遇怎么办？随着s元素的删除，s.size()会变小；
//             // if(i == j) break; //s的元素为奇数个
//             // if(i+j == s.size()-1) break; //s的元素为偶数个
//             if(s[i] != '(' && s[i] != ')') i++;
//             else if(s[i] == ')') s.erase(s.begin()+i); //erase函数的用法
//             else if(s[i] == '(') {
                
//                 if(s[j] != '(' && s[j] != ')' ) j--;
//                 else if(s[j] == '(') s.erase(s.begin()+j);
//                 else if(s[j] == ')') j--,i++;  //直到左右找到一对括号为止；

//             }

//         }
//         return s;
//     }
// };

//@DeepSeek/Gogogo222