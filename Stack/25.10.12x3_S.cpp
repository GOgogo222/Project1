// ջ�Ļ���ʵ�� 

// 1.ѧ������ôȡջ��Ԫ�أ���S.top--��*(S.top)
// 2.ѧ����ָ�����������point1-point2 = (ָ��1-ָ��2)/sizeof()
 

#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 //˳��ջ�洢�ṹ����
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}SqStack;  

//��ʼ��˳��ջS
void InitSqStack(SqStack &S)
{
    /*******************begin******************/
	S.base = new int[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
    /*******************end********************/	
}

//��Ԫ��e��ջ����ջ�ɹ�����true����ջʧ�ܷ���false
bool Push(SqStack &S, int e)
{
    /*******************begin******************/
	if (S.top - S.base >= S.stacksize)
        return false;

    *(S.top) = e;    // ��Ԫ��e����ջ��λ��
    S.top++;         // ջ��ָ������
    return true;
    /*******************end********************/	
}

//��ջ������ɾ��˳��ջS��ջ��Ԫ�أ��ò���e����ɾ����ջ��Ԫ�أ���ջ�ɹ�����true,ʧ�ܷ���false
bool Pop(SqStack &S,int &e)
{
    /*******************begin******************/
	if(S.top == S.base) return 0;
	
	e = *(--S.top);
	return true;
    /*******************end********************/	
}

//ȡ˳��ջS��ջ��Ԫ�أ��ò���e����ȡ�õ�ջ��Ԫ�أ�ȡֵ�ɹ�����������true,ʧ�ܷ���false
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

//��������a�е�ֵ��Ԫ����ջ���ջ(ֵΪ-1ʱ��ջ������ֵʱ��ջ),nΪ����a�ĳ���
void InOutS(SqStack &S, int a[], int n)
{
    /*******************begin******************/
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            // ��-1ֵ��ջ
            Push(S, a[i]);
        } else {
            // -1ֵ��ջ
            int e;
            if (Pop(S, e)) {
                // ��ջ�ɹ������ջ��Ԫ��
                cout << e << endl;
            } else {
                // ��ջʧ�ܣ�ջΪ��
                cout << "POP ERROR" << endl;
                break;  // �����������ݵ����
            }
        }
    }
    /*******************end********************/
}

int main(){
	SqStack S;   //����˳��ջS
	int n,array[MAXSIZE],i;   //n�洢ÿ��Ԫ������,array����洢ÿ��Ԫ��ֵ
	while(cin>>n&&n!=0){
		InitSqStack(S);    //��ʼ��˳��ջS
		i=0;
		while(n--){
			cin>>array[i++];  //����ÿ��Ԫ�أ��洢������array��
		}
		InOutS(S,array,i);   //��������a�е�ֵ��Ԫ����ջ���ջ
	}
	return 0;
}