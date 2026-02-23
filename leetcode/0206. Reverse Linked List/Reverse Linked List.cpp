#include <iostream>
#include "Reverse Linked List.h"
using namespace std;

int main() {
    Solution solution;

    ListNode* head = nullptr;
    for (int i = 0; i < 5; ++i) {
        head = new ListNode(4-i, head);
    }

    ListNode* reversedHead = solution.reverseList(head);

    for (ListNode* curr = reversedHead; curr != nullptr; curr = curr->next) {
        cout << curr->val << " ";
    }
    cout << endl;

    return 0;
}