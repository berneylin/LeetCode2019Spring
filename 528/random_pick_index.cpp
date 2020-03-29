#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        int lastSum = 0;
        for(int i=0;i<w.size();i++){
            this->weights.push_back({lastSum, lastSum+w[i]});
            lastSum += w[i];
        }
        this->maxW = this->weights[this->weights.size()-1].second;
    }
    
    int pickIndex() {
        // 生成[0, maxW) 的整数thisW， 如果thisW 落在区间[weights[i].first, weights[i].second)中， 返回i
        int thisW = rand()%maxW;
        // 二分查找
        int l = 0, r = weights.size() - 1, m;

        while(l<=r){
            int m = l + (r-l) / 2;
            int &curLow = weights[m].first;
            int &curHigh = weights[m].second;
            
            if(curLow<=thisW && thisW<curHigh){
                break;
            }else if(thisW >= curHigh){
                l = m+1;
            }else if(thisW < curLow){
                r = m-1;
            }
        }
        return m;
    }
private:
    vector<pair<int, int> > weights;
    int maxW = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */