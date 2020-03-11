#include<queue>
#include<cstring>
using namespace std;

class Solution {
public:
    int move[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    int calcSum(int m, int n) {
        int rtnNum = 0;
        while(m){
            rtnNum += m % 10;
            m /= 10;
        }
        while(n){
            rtnNum += n % 10;
            n /= 10;
        }
        return rtnNum;
    }

    int movingCount(int m, int n, int k) {
        queue<int> iQueue, jQueue;
        int visited[m][n];
        memset(visited, 0, sizeof(visited));
        iQueue.push(0);
        jQueue.push(0);
        int i, j, cnt = 0, nextI, nextJ;
        while(!iQueue.empty()) {
            i = iQueue.front();
            j = jQueue.front();
            iQueue.pop();
            jQueue.pop();
            if (i < 0 || i >= m || j < 0 || j >= n || calcSum(i, j) > k || visited[i][j] == 1) continue;
            else{
                visited[i][j] = 1;
                for (int moveIdx = 0; moveIdx < 4; moveIdx++) {
                    nextI = i + move[moveIdx][0];
                    nextJ = j + move[moveIdx][1];
                    iQueue.push(nextI);
                    jQueue.push(nextJ); 
                }
            }
        }
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                cnt += visited[i][j];
            }
        }
        return cnt;
    }
};