#include <iostream>
#include "Reorder List.h"
using namespace std;

int main() {
    Solution solution;
    ListNode* head = nullptr;

    for (int i = 5; i >= 1; --i) {
        ListNode* node = new ListNode{i, head};
        head = node;
    }

    ListNode* cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    solution.reorderList(head);
    cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}