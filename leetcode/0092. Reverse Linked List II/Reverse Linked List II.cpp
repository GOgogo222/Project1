#include "Reverse Linked List II.h"
#include <iostream>
using namespace std;

int main() {

    Solution solution;
    ListNode* head = new ListNode;
    ListNode* cur = head;
   
    for (int i = 0; i < 5; ++i) {
        cur->val = i + 1;
        if (i < 4) {
            cur->next = new ListNode;
            cur = cur->next;
        }
    }

    cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
    ListNode* res = solution.reverseBetween(head, 2, 4);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}

