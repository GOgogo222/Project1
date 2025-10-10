//��һ������Ҫ��ֿ�
//�������߼��Ƚϻ������������ֺ��ѣ�������һ������ͳ����ˣ�
//�ڴ�������new�����ڴ�ռ� ��Node* newNode = new Node; ��ȷ�� 
//�ṹ����󣺾�����ʹ��typedef struct ...  Node ��struct Node {
//    int data;
//    Node* next;
// }; ��ȷ�� 
//�������Node* head = NULL; ��ȷ 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// ��ȷ���������
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
        // ��������A
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
        
        // �������������ͷ�ڵ㣨�ڱ��ڵ㣩
        Node* posHead = new Node;  // ��ֵ����ͷ
        Node* negHead = new Node;  // ��ֵ����ͷ
        Node* posTail = posHead;
        Node* negTail = negHead;
        
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;  // ������һ���ڵ�
            
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
        
        // �������������ڱ��ڵ㣩
        out_Node(negHead->next);
        out_Node(posHead->next);
        
        // �ͷ��ڴ�
        // ������Ҫ�����ͷ����нڵ�
        // Ϊ������ʡ���ڴ��ͷŴ���
    }
    
    return 0;
}