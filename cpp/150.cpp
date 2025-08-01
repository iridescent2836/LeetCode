#include "header.h"
#include <functional>

// so ugly, the code is so very ugly. 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int len = tokens.size();
        for(int i = 0; i < len; i++){
            string temp = tokens[i];

            if(temp == "+"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num2+num1);

            } else if(temp == "-"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num2-num1);
            } else if(temp == "*"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num2*num1);
            } else if(temp == "/"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(num2/num1);
            } else{
                stk.push(stoi(temp));
            }
        }
        return stk.top();
    }
};

// prettier
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

// gorgeous
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> map = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}};
        stack<int> stk;
        for (string& s : tokens) {
            if (map.count(s)) {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                stk.push(map[s](left, right));
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
    
int main(){
    Solution s;
    vector<string> str = {"4","13","5","/","+"};
    cout << s.evalRPN(str) << endl;
    return 0;
}