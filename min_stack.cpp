#include<climits>
#include<vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        this->minElem = INT_MAX;  // initialize the minimum element with INT_MAX;
        this->len = 0;
        this->tail = stackArr.begin();
    }
    
    void push(int x) {
        this->len++;
        this->stackArr.push_back(x);
        this->tail++;
        if(this->minElem>x){
            this->minElem = x;
        }// update the minimum element in the stack
    }
    
    void pop() {
        len --;
        int currNum = *this->tail;
        this->stackArr.erase(this->tail);
        this->tail = this->stackArr.end()-1;
        if(currNum == this->minElem){
            //update the minimum element in the stack
            if(this->stackArr.empty()) this->minElem = INT_MAX;
            else{
                int thisMin = INT_MAX;
                for(vector<int>::iterator it=this->stackArr.begin();it!=stackArr.end();it++){
                    if(*it<thisMin) thisMin = *it;
                }
            }
        }
    }
    
    int top() {
        if(this->len==0) return 0;
        return *this->tail;
    }
    
    int getMin() {
        return this->minElem;
    }
public:
    int minElem;
    vector<int> stackArr;
    int len;
    vector<int>::iterator tail;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(void){
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    printf("%d\n", minStack.getMin());
    minStack.pop();
    printf("%d\n", minStack.top());
    printf("%d\n", minStack.getMin());
    return 0;
}