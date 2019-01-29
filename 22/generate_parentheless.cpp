#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(ret, "", 0, 0, n);
        return ret;
    }
    void generate(vector<string> &ret, string toBeDecide, int leftCnt, int rightCnt, int target){
        if(rightCnt>leftCnt||leftCnt>target||rightCnt>target) return;  // already illegal, pruning
        if(leftCnt==target && rightCnt==target){  // satisfy length condition and legal check
            ret.push_back(toBeDecide);
        }else{
            generate(ret, toBeDecide+"(", leftCnt+1, rightCnt, target);
            generate(ret, toBeDecide+")", leftCnt, rightCnt+1, target);
        }
    }
};

int main(void){
    int x;
    cin >> x;
    Solution *sol = new Solution();
    vector<string> ret;
    ret = sol->generateParenthesis(x);
    for(int i=0;i<ret.size();i++){
        cout << ret[i] << endl;
    }
    return 0;
}