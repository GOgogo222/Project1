//将一个链表按要求分开
//分析：逻辑比较基础，但是上手很难，但是这一个程序就出现了：
//内存分配错误：new开辟内存空间 （Node* newNode = new Node; 正确） 
//结构体错误：尽量不使用typedef struct ...  Node （struct Node {
//    int data;
//    Node* next;
// }; 正确） 
//建表错误：Node* head = NULL; 正确 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 正确的输出函数
void out_Node(Node* head) {
    if (head == NULL) return;
    
    Node* current = head;
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
        // 创建链表A
        Node* head = NULL;
        Node* tail = NULL;
        
        for (int i = 0; i < num; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node; // ***** !!! *****
            newNode->data = x;
            newNode->next = NULL;
            
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        // 创建正负链表的头节点（哨兵节点）
        Node* posHead = new Node;  // 正值链表头
        Node* negHead = new Node;  // 负值链表头
        Node* posTail = posHead;
        Node* negTail = negHead;
        
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;  // 保存下一个节点
            
            if (current->data > 0) {
                posTail->next = current;
                posTail = current;
                posTail->next = NULL;
            } else {
                negTail->next = current;
                negTail = current;
                negTail->next = NULL;
            }
            
            current = nextNode;
        }
        
        // 输出结果（跳过哨兵节点）
        out_Node(negHead->next);
        out_Node(posHead->next);
        
        // 释放内存
        // 这里需要遍历释放所有节点
        // 为简洁起见省略内存释放代码
    }
    
    return 0;
}