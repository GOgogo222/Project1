//��ת����
//ʱ�䣺O(n) �ռ䣺O(n)
//������ʹ�������ͷ�巨ʵ������
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
        if(!head) { //��������NULL
            return NULL;
        }
        ListNode* Top = new ListNode(); //ͷ���
        while(p1) { //һ����ͷ�������ʹ��ͷ�巨ʵ������
            ListNode* p2 = new ListNode(p1->val);
            p2->next = Top->next;
            Top->next = p2;
            p1 = p1->next; //ԭ����ָ�벻�Ϻ���            
        }
        return Top->next;
    }
};

//Gogogo222