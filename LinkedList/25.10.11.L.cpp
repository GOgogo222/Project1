//按要求修改链表 
//分析：1.大规模删除链表不可取，少量多次删除
//		2.大程序不释放内存会出问题 


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 正确的输出函数
void out_Node(Node* head) {
    if (head->next == NULL) {
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

int main() {
    int num;
    
    while (cin >> num && num != 0) {
        // 创建总链表A
        Node* head = new Node();
        //head->next = NULL:
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
		int mink,maxk;
		cin >> mink >> maxk;
		
// 删除在 [mink, maxk] 范围内的节点
        Node* prev = head;
        Node* curr = head->next;
        
        while (curr != NULL) {
            if (curr->data >= mink && curr->data <= maxk) {
                // 删除当前节点
                prev->next = curr->next;
                Node* toDelete = curr;
                curr = curr->next;
                delete toDelete;
            } else {
                // 移动到下一个节点
                prev = curr;
                curr = curr->next;
            }
        }   // 多次少量，避免空指针 
		out_Node(head); // 输出 
    }
    return 0;
}