//旋转链表
//@LeetCode
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }
        int len = 0; //链表长度
        ListNode *tempHead = head;
        while(tempHead != nullptr) {
            tempHead = tempHead->next; //不断向后移动
            len++;
        }
        k = k % len;
        //双指针
        ListNode *former = head;  // former指针
        ListNode *latter = head;  // latter指针
        for(int i = 0; i < k; i++) {
            former = former->next; 
        } // former向后移动k次

        while(former->next != nullptr) {
            former = former->next;
            latter = latter->next; // 两个指针一起移动;
        }
        former-> next = head;
        ListNode *newHead = latter->next;
        latter->next = nullptr;
        return newHead;
    }
};