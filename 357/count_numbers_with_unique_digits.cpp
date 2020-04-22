#include<vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // 10^n为(n+1)位数，则小于10^(n+1)代表最大为n位数
        if(n<=0) return 1;
        int cnt = 0;
        vector<int> cntMap(10, 0);
        vector<int> tmpVec;
        dfs(cntMap, tmpVec, n, cnt);
        return cnt;
    }

    void dfs(vector<int> &cntMap, vector<int> &tmpVec, int maxSize, int &cnt){
        if(tmpVec.size()>maxSize) return;
        if(tmpVec.size()==1 || (tmpVec.size()>1 && tmpVec.back()!=0)) cnt++;
        for(int i=0; i<=9; i++){
            if(cntMap[i]) continue;
            cntMap[i] = 1;
            tmpVec.push_back(i);
            dfs(cntMap, tmpVec, maxSize, cnt);
            tmpVec.pop_back();
            cntMap[i] = 0;
        }
    }
};