#include<queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((bigHeap.size()+smallHeap.size()) & 1){
            // 加入后变为偶数个
            if(!smallHeap.empty() && smallHeap.top() < num) {
                int tmp = smallHeap.top();
                smallHeap.pop();
                smallHeap.push(num);
                num = tmp;
            }
            bigHeap.push(num);
        } else {
            // 加入后变为奇数个
            if(!bigHeap.empty() && num < bigHeap.top()) {
                int tmp = bigHeap.top();
                bigHeap.pop();
                bigHeap.push(num);
                num = tmp;
            }
            smallHeap.push(num);
        }
    }
    
    double findMedian() {
        if(this->bigHeap.size() == this->smallHeap.size()) {
            int x = this->bigHeap.top(), y = this->smallHeap.top();
            return (double)(x) + ((double)(y-x))/2;
        } else {
            return (double)(this->smallHeap.top());
        }
    }
private:
    priority_queue<int> bigHeap;  // 默认大顶堆
    priority_queue<int , vector<int>, greater<int>> smallHeap;  // 小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */