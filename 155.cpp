#include "header.h"

class MinStack {
private:
    vector<int> stack;
    size_t minPos;
    size_t len;
public:
    MinStack() {
        this->len = 0;
        this->minPos = -1;    
    }
    
    void push(int val) {
        stack.push_back(val);
        if(len == 0)
            minPos = 0;
        else
            minPos = stack[minPos] < stack[len] ? minPos : len;
        len++;
    }
    
    void pop() {
        if(len == 0){
            cerr << "stack is empty, pop failed" << endl;
            exit(1);
        } else if(len == 1){
            stack.pop_back();
            minPos = -1;
        } else if(minPos!=len-1){
            stack.pop_back();
        } else { // scan the whole stack, and find the min element except the last element
            size_t temp = 0;
            for(size_t i = 0; i < len-1; i++){
                if(stack[i] < stack[temp]) temp = i;
            }
            stack.pop_back();
            minPos = temp;
        }
        len--;
    }
    
    int top() {
        if(len == 0){
            cerr << "stack is empty, failed to get the stack top" << endl;
            exit(1);
        }
        return stack[len-1];
    }
    
    int getMin() {
        if(len == 0){
            cerr << "stack is empty, failed to get the minimum element" << endl;
            exit(1);
        }
        return stack[minPos];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// using assistance stack
// for a stack `my_stack` has length `n`
// min_stack[i] = min(my_stack[0,...,i])
class MinStack {
private:
    stack<int> my_stack;
    stack<int> min_stack;
public:
    MinStack(){
        min_stack.push(INT32_MAX);
    }
    void push(int x){
        my_stack.push(x);
        min_stack.push(min(x, min_stack.top()));
    }
    void pop(){
        my_stack.pop();
        min_stack.pop();
    }
    int top(){
        return my_stack.top();
    }
    int getMin(){
        return min_stack.top();
    }
};