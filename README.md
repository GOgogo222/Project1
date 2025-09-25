# Project1
My first repository.I want to have a 100-Day challenge.
## September 25th Thursday Day 1
1.Split Linkedlist
```C++
//分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *smallHead = small;
        ListNode *large = new ListNode(0);
        ListNode *largeHead = large;
        while(head != nullptr) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
```
2.Rotate Linkedlist
```C++
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
```