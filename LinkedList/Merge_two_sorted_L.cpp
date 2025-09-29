//合并有序链表
//时间：O(n) 空间：O(1)
//分析：创建preHead第三方链表，将两个要合并的链表从头至尾一一比较，最后至多有一个没有合并完；
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* preHead = new ListNode(-1); // 头结点preHead
        ListNode* pre = preHead; // pre移动指针
        while(l1 && l2) {
            if(l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1 == NULL ? l2 : l1; // 最多有“一个”没有合并完
        return preHead->next;
    }
};

//LeetCode官方