//Ѱ�������k���ڵ�
//������˫ָ��-����ָ�뷨������ʵ��O��1����ЧѰ�ң�
//      ���ÿ�ָ����k��������ָ�������Ԫ�ڵ������
//      Ȼ������ָ��һ���ߣ�ֱ����ָ�뵽end->next��
//      ����slowָ���λ�þ���**������k��**�ڵ�
//˫ָ�뷨���㷺Ӧ���� ����������ڣ� �ж������Ƿ��л������м�ڵ�� 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// ��ȷ���������
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
        // ����������A
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
        } // �����ɹ�
        int k;
        cin >> k;
        
        // ��ȷ�ķ�����ʹ�ÿ���ָ���ҵ�����k���ڵ�
        Node* fast = head->next;
        Node* slow = head->next;
        
        // ��ָ������k��
        for (int i = 0; i < k && fast != NULL; i++) {
            fast = fast->next;
        }
        
        // ����ָ��ͬʱǰ����ֱ����ָ�뵽��ĩβ
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        Node* newhead = new Node;
        if (slow != NULL) {
            newhead->data = slow->data;
        } else {
            newhead->data = -1; // ���ߴ���������
        }
        newhead->next = NULL;
        
		out_newhead(newhead); // ��� 
    
    }
 
    return 0;
}