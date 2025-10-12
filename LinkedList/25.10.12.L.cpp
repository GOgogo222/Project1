//寻找链表第k个节点
//分析：双指针-快慢指针法，可以实现O（1）高效寻找；
//      先让快指针走k步（快慢指针均从首元节点出发）
//      然后两个指针一起走，直到快指针到end->next，
//      最终slow指针的位置就是**倒数第k个**节点
//双指针法还广泛应用于 查找链表入口， 判断链表是否有环，找中间节点等 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 正确的输出函数
void out_Node(Node* head) {
    if (head == NULL) {
    	cout << "no data!" << endl;
    	return;
	}
    Node* current = head->next;
    bool first = true;
    
    while (current != NULL) {
        if (!first) {
            cout << " ";
        }
        cout << current->data;
        first = false;
        current = current->next;
    }
    cout << endl;
}

void out_newhead(Node* head)
{
	if(head->data != -1) cout << head->data << endl;
	else cout << "no data!" << endl;
}

int main() {
    int num;
    
    while (cin >> num && num != 0) {
        // 创建总链表A
        Node* head = new Node();
        head->next = NULL;
        Node* tail = head;
        
        for (int i = 0; i < num; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node; 
            newNode->data = x;
            newNode->next = NULL;
            tail->next = newNode;
            tail = tail->next;
        } // 创建成功
        int k;
        cin >> k;
        
        // 正确的方法：使用快慢指针找倒数第k个节点
        Node* fast = head->next;
        Node* slow = head->next;
        
        // 快指针先走k步
        for (int i = 0; i < k && fast != NULL; i++) {
            fast = fast->next;
        }
        
        // 快慢指针同时前进，直到快指针到达末尾
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        Node* newhead = new Node;
        if (slow != NULL) {
            newhead->data = slow->data;
        } else {
            newhead->data = -1; // 或者处理错误情况
        }
        newhead->next = NULL;
        
		out_newhead(newhead); // 输出 
    
    }
 
    return 0;
}