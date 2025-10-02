//回文链表(1)
//时间：O(n) 空间；O(n)
//思路：创建一个数组；访问链表时将节点的val值一一存储；回文判断；

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector <int> arr;
        ListNode* p = head;
        while(p) {
            arr.push_back(p->val);
            p = p->next;
        }
        for(int i = 0,j = arr.size()-1; i <= j; i++, j--) { //回文数组判断，经典！！！
                                                            //一个循环判断中至多有3个";"
            if(arr[i] != arr[j]) return false;
        }
        return true;
    }
};

//@eetcode