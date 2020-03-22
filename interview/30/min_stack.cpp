#include <stack>
using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (_storeNum.empty()) {
            _minNum.push(x);
            _storeNum.push(x);
        } else {
            int currentMin = _minNum.top();
            _storeNum.push(x);
            _minNum.push(x<currentMin?x:currentMin);
        }
    }
    
    void pop() {
        if (!_storeNum.empty()) {
            _minNum.pop();
            _storeNum.pop();
        }
    }
    
    int top() {
        return _storeNum.empty()?-1:_storeNum.top();
    }
    
    int min() {
        return _minNum.empty()?-1:_minNum.top();
    }
private:
    stack<int> _minNum;
    stack<int> _storeNum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */