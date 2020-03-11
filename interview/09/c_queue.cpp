#include<stack>

using namespace std;

class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    
    int deleteHead() {
        int rtnNum = -1;
        if (!outStack.empty()){
            rtnNum = outStack.top();
            outStack.pop();
        }else{
            if (!inStack.empty()){
                while(!inStack.empty()) {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
                rtnNum = outStack.top();
                outStack.pop();
            }
        }
        return rtnNum;
    }
    stack<int> inStack;
    stack<int> outStack;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */