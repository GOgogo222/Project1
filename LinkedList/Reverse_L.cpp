//反转链表
//时间：O(n) 空间：O(n)
//分析：使用链表的头插法实现逆序
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
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = head;
        if(!head) { //空链表返回NULL
            return NULL;
        }
        ListNode* Top = new ListNode(); //头结点
        while(p1) { //一个带头结点链表，使用头插法实现逆序
            ListNode* p2 = new ListNode(p1->val);
            p2->next = Top->next;
            Top->next = p2;
            p1 = p1->next; //原链表指针不断后移            
        }
        return Top->next;
    }
};

//Gogogo222