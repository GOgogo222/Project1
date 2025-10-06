// 1249. �Ƴ���Ч������
// ʱ�䣺O(n)
//����������ָ�����������ϧ�ˣ��������������"())()((("->"()()"���������⣻

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left <= right) { // ��ָ��С�ڵ�����ָ�룡
            // ��ָ�룺�����������ַ�
            if (s[left] != '(' && s[left] != ')') {
                left++;
                continue;
            }
            
            // ��ָ�룺�����������ַ�
            if (s[right] != '(' && s[right] != ')') {
                right--;
                continue;
            }
            
            // �����ָ�����������ţ�ɾ����
            if (s[left] == ')') {
                s.erase(s.begin() + left);
                right--; // �ַ������ȼ��٣��ұ߽�ǰ��
                continue;
            }
            
            // �����ָ�����������ţ�ɾ����
            if (s[right] == '(') {
                s.erase(s.begin() + right);
                right--; // �ַ������ȼ��٣��ұ߽�ǰ��
                continue;
            }
            
            // �����ָ����������������ָ�����������ţ�ƥ��ɹ�
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
//         //1.��ô�����Ч��
//         //2.��ô������Ч��
//         //�����洢�������ŵ�ջͬʱ����Ԫ�أ����Ǵ洢������������ģ������������ø�ԭԭ�����ַ����ˣ�
//         //���Դ�ͷβ���߿�ʼ������
//         string t;
//         int i = 0,j = s.size()-1;
//         int n = s.size();  //������ʼ����
//         for(; i < s.size(), j > 0;) { //ż���޷�������ô�죿����sԪ�ص�ɾ����s.size()���С��
//             // if(i == j) break; //s��Ԫ��Ϊ������
//             // if(i+j == s.size()-1) break; //s��Ԫ��Ϊż����
//             if(s[i] != '(' && s[i] != ')') i++;
//             else if(s[i] == ')') s.erase(s.begin()+i); //erase�������÷�
//             else if(s[i] == '(') {
                
//                 if(s[j] != '(' && s[j] != ')' ) j--;
//                 else if(s[j] == '(') s.erase(s.begin()+j);
//                 else if(s[j] == ')') j--,i++;  //ֱ�������ҵ�һ������Ϊֹ��

//             }

//         }
//         return s;
//     }
// };

//@DeepSeek/Gogogo222