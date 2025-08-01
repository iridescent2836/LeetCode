#include "header.h"
// use 2 stacks
class BrowserHistory {
public:

    BrowserHistory(string homepage) {
        this->homepage = homepage;
        backwardHistory.push(homepage);
    }
    
    void visit(string url) {
        while(!this->forwardHistory.empty()){
            this->forwardHistory.pop();
        }
        this->backwardHistory.push(url);
    }
    
    string back(int steps) {
        string url;

        for(int i = 0; i < steps && !this->backwardHistory.empty(); i++){
            url=this->backwardHistory.top();
            this->backwardHistory.pop();
            this->forwardHistory.push(url);
            

            if(!this->backwardHistory.empty())
                url = this->backwardHistory.top();
            else{
                url = this->homepage;
                this->backwardHistory.push(url);
                this->forwardHistory.pop();
                break;
            }
        }

        return url;
    }
    
    string forward(int steps) {
        string url = this->backwardHistory.top();
        for(int i = 0; i < steps && !this->forwardHistory.empty(); i++) {
            url = this->forwardHistory.top();
            this->forwardHistory.pop();
            this->backwardHistory.push(url);
            if(!this->forwardHistory.empty())
                ;
            else{
                url = this->backwardHistory.top();
                break;
            }
        }
        return url;
    }
private:
    string homepage;
    stack<string> backwardHistory;
    stack<string> forwardHistory;

};

// use one vector
class BrowserHistory {
public:

    BrowserHistory(string homepage) {
        this->homepage = homepage;
        this->sizeOfHistory =  1;
        this->idx = 0;
        this->lenOfVector = 1;
        this->history.push_back(homepage);
    }
    
    void visit(string url) {
        if(lenOfVector == idx + 1){
            this->idx++;
            this->lenOfVector++;
            this->sizeOfHistory++;
            this->history.push_back(url);

        }
        else{
            this->history[idx+1]= url;
            idx++;
            sizeOfHistory = idx+1;
        }

    }
    
    string back(int steps) {
        if(idx < steps)
            idx = 0;
        else
            idx-=steps;
        
        return history[idx];
    }
    
    string forward(int steps) {
        if(steps + idx > this->sizeOfHistory-1)
            idx = sizeOfHistory-1;
        else
            idx += steps;
        return history[idx];
    }
private:
    vector<string> history;
    string homepage;
    int sizeOfHistory;
    int idx;
    int lenOfVector;
};