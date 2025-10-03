//��Сջ
//������ջ��vector������߼����ƣ�����һ���µ�ջ������ջ�е���Сֵ����ջ�����Ծ������޷�������
//
class MinStack {
    vector<int> stack;
    vector<int> Min_Stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    } // kk
    
    void push(int x) {
        stack.push_back(x);
        if(Min_Stack.empty() || x <= Min_Stack.back()) // "<="�ظ���MinDataҲҪ��ջ
            Min_Stack.push_back(x);
    }
    
    void pop() {
        if(Min_Stack.empty()) return; // ������Ϊvoid�޷���ֵ��������return�ж�
        if(Min_Stack.back() == stack.back())
            Min_Stack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return Min_Stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 //@DeepSeek and me