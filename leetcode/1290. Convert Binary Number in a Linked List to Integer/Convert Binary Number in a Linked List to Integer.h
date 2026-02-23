#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* p = head;
        while (p) {
            ans = ans * 2 + p->val;
            p = p->next;
        }
        return ans;
    }
};
