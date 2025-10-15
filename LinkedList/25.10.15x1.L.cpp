//����ڵ���� 
//�Ѷȣ�һ��
 
//***********************************
void InitList_L(LinkList &L)
{
    /**************begin************/
    L = new LNode;
	L->next = NULL;
    /**************end************/
}
//...
        // �����½ڵ�
        LNode *p = new LNode;
        strcpy(p->data.no, no);
        strcpy(p->data.name, name);
        p->data.price = price;
        p->next = NULL;
//...   
//************************************

// ��������������Ҫע�⣺
// 1.ע�ⴴ���½ڵ�ʱ���ڵ����� strcpy ���صĸ�ֵ��ʽ��char[]���;Ͳ������� "=" �ˣ�
// 2.���LinkList������һ��ָ�룬newһ����LNode��LinkList�������壻 



#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

//ͼ����Ϣ���Ͷ���
typedef struct
{
    char no[20];    //ͼ��ISBN
    char name[50];   //ͼ������
    float price;   //ͼ��۸�
}Book;

//ͼ����Ϣ�����ʽ�洢�ṹ
typedef struct LNode
{
    Book data;    	//����������
    struct LNode *next; //ָ����
}LNode,*LinkList;

//����һ���յĵ�����L����ֻ��һ��ͷ���ĵ�����L��
//void InitList_L(LinkList &L)
//{
//    /**************begin************/
//    L = new LNode;
//	L->next = NULL;
//    /**************end************/
//}

//�������ͼ����Ϣ�洢��������L��,(Ҫ��ʹ��β�巨��������L��
void CreateList_R(LinkList &L)
{
    L = new LNode;   // ����ͷ���
    L->next = NULL;
    LNode *r = L;    // βָ�룬��ʼָ��ͷ���

    while (true) {
        char no[20];
        char name[50];
        float price;

        cin >> no;

        if (strcmp(no, "0") == 0) break;  // ���� 0 ����

        cin >> name >> price;

        // �����½ڵ�
        LNode *p = new LNode;
        strcpy(p->data.no, no);
        strcpy(p->data.name, name);
        p->data.price = price;
        p->next = NULL;

        // β��
        r->next = p;
        r = p;
    }
}

//������ı�����ͼ�����ͼ�����
int  Length_L(LinkList L)
{
   /**************begin************/
	LNode* p = L->next;
	int num = 0;
	while(p) {
		num++;
		p = p->next;
	}
	return num;
    /**************end************/
    
}


//����������(�����L�����е�ͼ��,ÿ��ͼ��ռһ�У����һ��ͼ����޿��У�
void Output_L(LinkList L)
{
    /**************begin************/
   	LNode* p = L->next;
   	while(p) {
   		cout << p->data.no << " " << p->data.name << " " 
		     << fixed << setprecision(2) << p->data.price;
		if(p->next) cout << endl; // �����һ���ڵ��Ƿ�Ϊ�գ�
		p = p->next; 
	}
    /**************end************/
}
int main()
{
	LinkList L;    //���嵥����L
	InitList_L(L);  //��ʼ��������L
	CreateList_R(L);  //�������ͼ����Ϣ�洢��������L��,(Ҫ��ʹ��β�巨��������L��
	int len=Length_L(L);  //������ı�����ͼ�����ͼ�����
	cout<<len<<endl;  //�����
	Output_L(L);   //���L�����е�ͼ��
	return 0;
}
