#include <iostream>
#include "Linked List Cycle.h"
using namespace std;

int main() {

    Solution solution;


    ListNode* head = new ListNode{3, nullptr};
    ListNode* node2 = new ListNode{2, nullptr};
    ListNode* node0 = new ListNode{0, nullptr};
    ListNode* node4 = new ListNode{-4, nullptr};
    

    head->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = head; // Create a cycle

    bool result = solution.hasCycle(head);
    cout << "Has cycle: " << (result ? "true" : "false") << endl;

    return 0;
}