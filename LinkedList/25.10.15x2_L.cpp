// 链表的逆置
// 难度：一般

//*************************
void Reverse_L(LinkList &L)
{
    /**************begin************/
    LNode *p = L->next;     // 指向第一个实际节点
    L->next = NULL;         // 断开头结点与后续的链接

    while (p) {
        LNode *q = p->next; // 暂存下一个节点
        p->next = L->next;  // 插入到头结点之后（头插法）
        L->next = p;        // 更新头结点的后继
        p = q;              // 继续处理下一个节点
    }
    /**************end************/
}
//**************************

// “原地”逆置链表 
// 这个实现非常棒！相比于新建链表实现逆置而言，有很多的优势

#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

//图书信息类型定义
typedef struct
{
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;


//图书信息表的链式存储结构
typedef struct LNode
{
    Book data;    	//结点的数据域
    struct LNode *next; //指针域
}LNode,*LinkList;


void InitList_L(LinkList &L)
{
    /**************begin************/
    L = new LNode;
	L->next = NULL;
    /**************end************/
}

//将读入的图书信息存储到单链表L中,(要求使用尾插法建单链表L）
void CreateList_R(LinkList &L)
{
	int n;   //存储读入的图书数量
	LNode *s,*r=L;   //s指向新结点,r为尾指针
	cin>>n;   //读入图书数量
	while(n--){
		s=new LNode;   //创建新结点
		cin>>s->data.no>>s->data.name>>s->data.price;  //将读入的一本书信息存储到s结点中 ！！！ 
		r->next=s;  //将s结点插入到单链表L的尾部
		r=s;  //更新尾指针,使其指向新的尾结点
	}
	r->next=NULL;  //链表尾结点指针域置空
}

void Reverse_L(LinkList &L)
{
    /**************begin************/
    LNode *p = L->next;     // 指向第一个实际节点
    L->next = NULL;         // 断开头结点与后续的链接

    while (p) {
        LNode *q = p->next; // 暂存下一个节点
        p->next = L->next;  // 插入到头结点之后（头插法）
        L->next = p;        // 更新头结点的后继
        p = q;              // 继续处理下一个节点
    }
    /**************end************/
}


//单链表的输出(即输出L中所有的图书,每本图书占一行，最后一本图书后无空行）
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
	LinkList L;    //定义单链表L
	L=new LNode;   //初始化单链表L
	L->next=NULL;
	CreateList_R(L);  //将读入的图书信息存储到单链表L中
	Reverse_L(L);   //将单链表L中的数据逆序存储
	Output_L(L);   //输出L中所有的图书
	return 0;
}