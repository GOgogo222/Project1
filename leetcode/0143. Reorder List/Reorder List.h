
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    // 876. 链表的中间节点
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // 206. 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* middle = middleNode(head);
        ListNode* head2 = reverseList(middle);
        while (head2->next) {
            ListNode* nxt = head->next;
            ListNode* nxt2 = head2->next;
            head->next = head2;
            head2->next = nxt;
            head = nxt;
            head2 = nxt2;
        }
    }
};
