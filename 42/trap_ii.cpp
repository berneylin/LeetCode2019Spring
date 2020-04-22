#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> monoStack;  // 单调栈内存索引值
        for(int i=0; i<height.size(); i++){
            while(!monoStack.empty() && height[monoStack.top()] < height[i]){
                int midHeight = height[monoStack.top()];
                monoStack.pop();
                if(monoStack.empty()){
                    // 如果没有左边界了
                    break;
                }
                int leftIdx = monoStack.top(), leftHeight = height[monoStack.top()];
                int thisArea = (i-leftIdx-1)*(min(leftHeight, height[i])-midHeight);
                ans += thisArea;
            }
            monoStack.push(i);
        }
        return ans;
    }
};