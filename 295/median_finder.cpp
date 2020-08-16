class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty() ||　num<maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        // modify
        if(maxHeap.size()==(minHeap.size()+2)){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size()==(maxHeap.size()+2)){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (double)(minHeap.top()+maxHeap.top()) / 2.0;
        }else{
            return (double)((minHeap.size()>maxHeap.size())?minHeap.top():maxHeap.top());
        }
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};