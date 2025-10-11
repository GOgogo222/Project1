//��Ҫ���޸����� 
//������1.���ģɾ��������ȡ���������ɾ��
//		2.������ͷ��ڴ������� 


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// ��ȷ���������
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
        // ����������A
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
        } // �����ɹ�
		int mink,maxk;
		cin >> mink >> maxk;
		
// ɾ���� [mink, maxk] ��Χ�ڵĽڵ�
        Node* prev = head;
        Node* curr = head->next;
        
        while (curr != NULL) {
            if (curr->data >= mink && curr->data <= maxk) {
                // ɾ����ǰ�ڵ�
                prev->next = curr->next;
                Node* toDelete = curr;
                curr = curr->next;
                delete toDelete;
            } else {
                // �ƶ�����һ���ڵ�
                prev = curr;
                curr = curr->next;
            }
        }   // ��������������ָ�� 
		out_Node(head); // ��� 
    }
    return 0;
}