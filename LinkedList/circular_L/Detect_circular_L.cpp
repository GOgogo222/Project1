//判断环形链表
//时间复杂度：O(n)
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
    bool hasCycle(ListNode *head) {
       if(head == NULL || head->next == NULL) {
        return false;
    }
    ListNode* fast = head; //快指针
    ListNode* low = head; //慢指针
    while(fast && fast->next) {
        low = low->next; // 1节点/每次
        fast = fast->next->next; // 2节点/每次
        if(low == fast) return true; // 若有环形链表，且指针速度不同，则指针必定相遇
    }
    return false;
    }
};

// DeepSeek