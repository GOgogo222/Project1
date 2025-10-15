// ���������
// �Ѷȣ�һ��

//*************************
void Reverse_L(LinkList &L)
{
    /**************begin************/
    LNode *p = L->next;     // ָ���һ��ʵ�ʽڵ�
    L->next = NULL;         // �Ͽ�ͷ��������������

    while (p) {
        LNode *q = p->next; // �ݴ���һ���ڵ�
        p->next = L->next;  // ���뵽ͷ���֮��ͷ�巨��
        L->next = p;        // ����ͷ���ĺ��
        p = q;              // ����������һ���ڵ�
    }
    /**************end************/
}
//**************************

// ��ԭ�ء��������� 
// ���ʵ�ַǳ�����������½�����ʵ�����ö��ԣ��кܶ������

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


void InitList_L(LinkList &L)
{
    /**************begin************/
    L = new LNode;
	L->next = NULL;
    /**************end************/
}

//�������ͼ����Ϣ�洢��������L��,(Ҫ��ʹ��β�巨��������L��
void CreateList_R(LinkList &L)
{
	int n;   //�洢�����ͼ������
	LNode *s,*r=L;   //sָ���½��,rΪβָ��
	cin>>n;   //����ͼ������
	while(n--){
		s=new LNode;   //�����½��
		cin>>s->data.no>>s->data.name>>s->data.price;  //�������һ������Ϣ�洢��s����� ������ 
		r->next=s;  //��s�����뵽������L��β��
		r=s;  //����βָ��,ʹ��ָ���µ�β���
	}
	r->next=NULL;  //����β���ָ�����ÿ�
}

void Reverse_L(LinkList &L)
{
    /**************begin************/
    LNode *p = L->next;     // ָ���һ��ʵ�ʽڵ�
    L->next = NULL;         // �Ͽ�ͷ��������������

    while (p) {
        LNode *q = p->next; // �ݴ���һ���ڵ�
        p->next = L->next;  // ���뵽ͷ���֮��ͷ�巨��
        L->next = p;        // ����ͷ���ĺ��
        p = q;              // ����������һ���ڵ�
    }
    /**************end************/
}


//����������(�����L�����е�ͼ��,ÿ��ͼ��ռһ�У����һ��ͼ����޿��У�
void Output_L(LinkList L)
{
   	LNode *p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price;
		if(p->next) cout<<endl;
		p=p->next;
	} 
}

int main()
{
	LinkList L;    //���嵥����L
	L=new LNode;   //��ʼ��������L
	L->next=NULL;
	CreateList_R(L);  //�������ͼ����Ϣ�洢��������L��
	Reverse_L(L);   //��������L�е���������洢
	Output_L(L);   //���L�����е�ͼ��
	return 0;
}