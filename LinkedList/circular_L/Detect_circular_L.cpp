//�жϻ�������
//ʱ�临�Ӷȣ�O(n)
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
    ListNode* fast = head; //��ָ��
    ListNode* low = head; //��ָ��
    while(fast && fast->next) {
        low = low->next; // 1�ڵ�/ÿ��
        fast = fast->next->next; // 2�ڵ�/ÿ��
        if(low == fast) return true; // ���л���������ָ���ٶȲ�ͬ����ָ��ض�����
    }
    return false;
    }
};

// DeepSeek