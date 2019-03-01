
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if(rowIndex==0) return ans;
        ans.push_back(1);
        if(rowIndex==1) return ans;
        for(int i=1;i<rowIndex;i++){
            ans.push_back(1);
            for(int j=i;j>0;j--){
                // reverse order handle
                ans[j] = ans[j-1] + ans[j];
            }
        }
        return ans;
    }
};