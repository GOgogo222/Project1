//��������(1)
//ʱ�䣺O(n) �ռ䣻O(n)
//˼·������һ�����飻��������ʱ���ڵ��valֵһһ�洢�������жϣ�

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
    bool isPalindrome(ListNode* head) {
        vector <int> arr;
        ListNode* p = head;
        while(p) {
            arr.push_back(p->val);
            p = p->next;
        }
        for(int i = 0,j = arr.size()-1; i <= j; i++, j--) { //���������жϣ����䣡����
                                                            //һ��ѭ���ж���������3��";"
            if(arr[i] != arr[j]) return false;
        }
        return true;
    }
};

//@eetcode