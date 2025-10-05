//�沨�����ʽ��ֵ
//ʱ�䣺O(n) �ռ䣺O(n) ��������100%�û����Ҿ�֪��������
//��������Ҫ�ѵ��Ƕ�string�������ַ�����ת����int���ͣ�ʹ��stoi����
//      �����"" �� ''������Щģ���ˣ�
//      switch(token[i])�ǷǷ��ģ�����string t = token[i]; Ȼ��switch(t)����;

class Solution {
public:
    void stack_operator_plus(vector<int>& arr) { // ��
        int a = arr[arr.size()-2] + arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    void stack_operator_subtract(vector<int>& arr) { // ��
        int a = arr[arr.size()-2] - arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    void stack_operator_Multiplication(vector<int>& arr) { // ��
        int a = arr[arr.size()-2] * arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    void stack_operator_division(vector<int>& arr) {  // ��
        int a = arr[arr.size()-2] / arr[arr.size()-1];
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stack_a;
        for(int i = 0; i < n; i++) { //*i=0��1��ô����?* ��tokens�ı�������û���������
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" ) {
                int a = stoi(tokens[i]);
                stack_a.push_back(a);
            } else {
                if(tokens[i] == "+") stack_operator_plus(stack_a); // ��
                if(tokens[i] == "-") stack_operator_subtract(stack_a); // ��
                if(tokens[i] == "*") stack_operator_Multiplication(stack_a); // ��
                if(tokens[i] == "/") stack_operator_division(stack_a); // ��
            }
        }
        return stack_a.back();
    }
};

//@Gogogo222