#include<vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<bool> used(N+1, false);
        dfs(0, 0, used, N);
        return _ans;
    }

    void dfs(int curNum, int curIdx, vector<bool> &used, const int &N){
        if(curNum!=0 && (curIdx%curNum)&&(curNum%curIdx)) return;
        if(curIdx==N) {
            _ans++;
            return;
        }

        for(int i=1; i<=N; i++){
            if(used[i]) continue;
            used[i] = true;
            dfs(i, curIdx+1, used, N);
            used[i] = false;
        }
    }
private:
    int _ans = 0;
};