//相交链表
//双指针补偿法
//时间：O(n) 空间：O(1);
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *pa = headA, *pb = headB;
        while(pa != pb) {
            // 指针是否是尾节点？如果是pa->next = headB / pb->next = headB;  
            pa = pa ? pa->next : headB; 
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};

// DeepSeek