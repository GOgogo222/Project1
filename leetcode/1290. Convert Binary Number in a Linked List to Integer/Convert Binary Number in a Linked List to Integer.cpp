#include <iostream>
#include "Convert Binary Number in a Linked List to Integer.h"
using namespace std;

int main() {
    ListNode* p = new ListNode(1);
    p->next = new ListNode(0);
    p->next->next = new ListNode(1);
 
    Solution solution;
    cout << solution.getDecimalValue(p) << endl;

    return 0;
}
