//最小栈
//分析：栈和vector数组的逻辑类似；创建一个新的栈来处理栈中的最小值，由栈的特性决定（无法遍历）
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
        if(Min_Stack.empty() || x <= Min_Stack.back()) // "<="重复的MinData也要入栈
            Min_Stack.push_back(x);
    }
    
    void pop() {
        if(Min_Stack.empty()) return; // 本函数为void无返回值，所以用return中断
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