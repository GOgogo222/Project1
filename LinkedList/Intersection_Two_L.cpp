//�ཻ����
//˫ָ�벹����
//ʱ�䣺O(n) �ռ䣺O(1);
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
            // ָ���Ƿ���β�ڵ㣿�����pa->next = headB / pb->next = headB;  
            pa = pa ? pa->next : headB; 
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};

// DeepSeek