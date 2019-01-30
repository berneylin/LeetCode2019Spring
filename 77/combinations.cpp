class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        bool isVisited[n+1];
        memset(isVisited, 0, (n+1)*sizeof(bool));
        vector<vector<int> > ans;
        vector<int> elem;
        dfs(ans, elem, isVisited, n, k, 1);
        return ans;
    }

    void dfs(vector<vector<int> > &ans, vector<int> &elem, bool* isVisited, int n, int k, int start){
        if(elem.size()==k) ans.push_back(elem);
        else{
            for(int i=start;i<=n;i++){
                if(isVisited[i]) continue;
                elem.push_back(i);
                isVisited[i] = true;
                dfs(ans, elem, isVisited, n, k, start+1);
                isVisited[i] = false;
                elem.pop_back();
            }
        }
    }
};