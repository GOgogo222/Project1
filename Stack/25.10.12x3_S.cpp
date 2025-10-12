// 栈的基本实现 

// 1.学会了怎么取栈顶元素，先S.top--再*(S.top)
// 2.学会了指针相减操作，point1-point2 = (指针1-指针2)/sizeof()
 

#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 //顺序栈存储结构定义
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}SqStack;  

//初始化顺序栈S
void InitSqStack(SqStack &S)
{
    /*******************begin******************/
	S.base = new int[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
    /*******************end********************/	
}

//将元素e入栈，入栈成功返回true，入栈失败返回false
bool Push(SqStack &S, int e)
{
    /*******************begin******************/
	if (S.top - S.base >= S.stacksize)
        return false;

    *(S.top) = e;    // 将元素e放入栈顶位置
    S.top++;         // 栈顶指针上移
    return true;
    /*******************end********************/	
}

//出栈操作，删除顺序栈S的栈顶元素，用参数e返回删除的栈顶元素，出栈成功返回true,失败返回false
bool Pop(SqStack &S,int &e)
{
    /*******************begin******************/
	if(S.top == S.base) return 0;
	
	e = *(--S.top);
	return true;
    /*******************end********************/	
}

//取顺序栈S的栈顶元素，用参数e返回取得的栈顶元素，取值成功，函数返回true,失败返回false
bool GetTop(SqStack S,int &e)
{
    /*******************begin******************/
	if(S.top == S.base) {
		cout << "POP ERROR" << endl;
		return 0;
	}
	
	e = *(S.top - 1);
	return true;
    /*******************end********************/
}

//根据数组a中的值将元素入栈或出栈(值为-1时出栈，其它值时入栈),n为数组a的长度
void InOutS(SqStack &S, int a[], int n)
{
    /*******************begin******************/
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            // 非-1值入栈
            Push(S, a[i]);
        } else {
            // -1值出栈
            int e;
            if (Pop(S, e)) {
                // 出栈成功，输出栈顶元素
                cout << e << endl;
            } else {
                // 出栈失败，栈为空
                cout << "POP ERROR" << endl;
                break;  // 结束本组数据的输出
            }
        }
    }
    /*******************end********************/
}

int main(){
	SqStack S;   //定义顺序栈S
	int n,array[MAXSIZE],i;   //n存储每组元素数量,array数组存储每组元素值
	while(cin>>n&&n!=0){
		InitSqStack(S);    //初始化顺序栈S
		i=0;
		while(n--){
			cin>>array[i++];  //读入每组元素，存储到数组array中
		}
		InOutS(S,array,i);   //根据数组a中的值将元素入栈或出栈
	}
	return 0;
}