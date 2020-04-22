#include<vector>
#include<set>
using namespace std;

class UnionFindSet {
public:
    UnionFindSet(int size) {
        this->pre = vector<int>(size);
        for(int i=0; i<size; i++){
            this->pre[i] = i;
        }
        this->cnt = size;
    }

    int find(int i) {
        if(i!=pre[i]) pre[i] = find(pre[i]);
        return pre[i];
    }

    void unionJoin(int i, int j) {
        int iRoot = find(i);
        int jRoot = find(j);
        if(iRoot==jRoot) return;
        this->pre[iRoot] = jRoot;
        this->cnt--;
    }

    int getCount(void) {
        return this->cnt;
    }
private:
    vector<int> pre;
    int cnt;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty() || M.size() != M[0].size()) return 0;
        int N = M.size();

        UnionFindSet uf(N); // 并查集

        for(int i=0; i<N; i++){
            for(int j=i-1; j>=0; j--){
                if(M[i][j]==1){
                    uf.unionJoin(i, j);
                }
            }
        }


        return uf.getCount();
    }
};