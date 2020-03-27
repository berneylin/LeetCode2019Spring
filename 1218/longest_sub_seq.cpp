#include<vector>
#include<cstring>

using namespace std;


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        if(arr.empty()) return 0;
        int dp[arr.size()];
        int tmpArr[20001];
        int OFFSET = 10000;
        int ans = 1;
        for(int i=0;i<20001;i++) tmpArr[i] = -1;

        for (int i=0;i<arr.size();i++){
            // 推算diff数的坐标在tmpArr中的索引diffNumIdx
            // 有关系 arr[i]-arr[j] == difference => arr[j] == arr[i] - difference
            int diffNumIdx = OFFSET+arr[i]-difference;
            if (diffNumIdx>=0 && diffNumIdx<20001 && tmpArr[diffNumIdx] != -1) {
                dp[i] = dp[tmpArr[diffNumIdx]] + 1;
            } else {
                dp[i] = 1;
            }
            // 更新最大值
            ans = dp[i]>ans?dp[i]:ans;
            // 记录当前arr[i]的坐标i
            tmpArr[OFFSET+arr[i]] = i;
        }
        return ans;
    }
};