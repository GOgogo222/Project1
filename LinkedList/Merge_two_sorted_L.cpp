//�ϲ���������
//ʱ�䣺O(n) �ռ䣺O(1)
//����������preHead����������������Ҫ�ϲ��������ͷ��βһһ�Ƚϣ����������һ��û�кϲ��ꣻ
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
        ListNode* preHead = new ListNode(-1); // ͷ���preHead
        ListNode* pre = preHead; // pre�ƶ�ָ��
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
        pre->next = l1 == NULL ? l2 : l1; // ����С�һ����û�кϲ���
        return preHead->next;
    }
};

//LeetCode�ٷ�