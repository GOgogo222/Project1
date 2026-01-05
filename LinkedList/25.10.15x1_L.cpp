//计算节点个数 
//难度：一般
 
//***********************************
void InitList_L(LinkList &L)
{
    /**************begin************/
    L = new LNode;
	L->next = NULL;
    /**************end************/
}
//...
        // 创建新节点
        LNode *p = new LNode;
        strcpy(p->data.no, no);
        strcpy(p->data.name, name);
        p->data.price = price;
        p->next = NULL;
//...   
//************************************

// 总体上有两点需要注意：
// 1.注意创建新节点时，节点数据 strcpy 独特的赋值方式，char[]类型就不可以是 "=" 了；
// 2.清楚LinkList不过是一个指针，new一个新LNode，LinkList才有意义； 



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

//构造一个空的单链表L（即只有一个头结点的单链表L）
//void InitList_L(LinkList &L)
//{
//    /**************begin************/
//    L = new LNode;
//	L->next = NULL;
//    /**************end************/
//}

//将读入的图书信息存储到单链表L中,(要求使用尾插法建单链表L）
void CreateList_R(LinkList &L)
{
    L = new LNode;   // 建立头结点
    L->next = NULL;
    LNode *r = L;    // 尾指针，初始指向头结点

    while (true) {
        char no[20];
        char name[50];
        float price;

        cin >> no;

        if (strcmp(no, "0") == 0) break;  // 输入 0 结束

        cin >> name >> price;

        // 创建新节点
        LNode *p = new LNode;
        strcpy(p->data.no, no);
        strcpy(p->data.name, name);
        p->data.price = price;
        p->next = NULL;

        // 尾插
        r->next = p;
        r = p;
    }
}

//求链表的表长，即图书表中图书个数
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


//单链表的输出(即输出L中所有的图书,每本图书占一行，最后一本图书后无空行）
void Output_L(LinkList L)
{
    /**************begin************/
   	LNode* p = L->next;
   	while(p) {
   		cout << p->data.no << " " << p->data.name << " " 
		     << fixed << setprecision(2) << p->data.price;
		if(p->next) cout << endl; // 检测下一个节点是否为空；
		p = p->next; 
	}
    /**************end************/
}
int main()
{
	LinkList L;    //定义单链表L
	InitList_L(L);  //初始化单链表L
	CreateList_R(L);  //将读入的图书信息存储到单链表L中,(要求使用尾插法建单链表L）
	int len=Length_L(L);  //求链表的表长，即图书表中图书个数
	cout<<len<<endl;  //输出表长
	Output_L(L);   //输出L中所有的图书
	return 0;
}
