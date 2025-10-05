//逆波兰表达式求值
//时间：O(n) 空间：O(n) 均超过近100%用户！我就知道你能行
//分析：主要难点是对string数组中字符类型转换成int类型（使用stoi）；
//      另外对"" 和 ''记忆有些模糊了；
//      switch(token[i])是非法的！先令string t = token[i]; 然后switch(t)即可;

class Solution {
public:
    void stack_operator_plus(vector<int>& arr) { // 加
        int a = arr[arr.size()-2] + arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    void stack_operator_subtract(vector<int>& arr) { // 减
        int a = arr[arr.size()-2] - arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    void stack_operator_Multiplication(vector<int>& arr) { // 乘
        int a = arr[arr.size()-2] * arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    void stack_operator_division(vector<int>& arr) {  // 除
        int a = arr[arr.size()-2] / arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stack_a;
        for(int i = 0; i < n; i++) { //*i=0或1怎么处理?* 对tokens的遍历。答：没有这种情况
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" ) {
                int a = stoi(tokens[i]);
                stack_a.push_back(a);
            } else {
                if(tokens[i] == "+") stack_operator_plus(stack_a); // 加
                if(tokens[i] == "-") stack_operator_subtract(stack_a); // 减
                if(tokens[i] == "*") stack_operator_Multiplication(stack_a); // 乘
                if(tokens[i] == "/") stack_operator_division(stack_a); // 除
            }
        }
        return stack_a.back();
    }
};

//@Gogogo222