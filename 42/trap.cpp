#include<stack>
#include<vector>
using namespace std;



class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> monoStack;
        int ans = 0;

        for(int i=0; i<height.size(); i++){
            while(!monoStack.empty() && height[monoStack.top()] < height[i]) {
                int lastHeightIdx = monoStack.top();
                monoStack.pop();
                if(monoStack.empty())  // 说明没有左边界
                    break;

                // 当前的栈顶为左边界
                int leftIdx = monoStack.top();
                int leftHeight = height[leftIdx];
                int thisWidth = i - 1 - leftIdx;
                int thisHeight = (height[i]<leftHeight?height[i]:leftHeight) - height[lastHeightIdx];
                ans += thisWidth * thisHeight;
            }
            monoStack.push(i);
        }


        return ans;

    }
};