#include "Add Two Numbers.h"
#include <iostream>
using namespace std;

int main() {
    Solution solution;

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = solution.addTwoNumbers(l1, l2);
    while (result) {
        cout << result->val << " "; // Output: 7 0 8
        result = result->next;
    }
    cout << endl;

    return 0;
}
