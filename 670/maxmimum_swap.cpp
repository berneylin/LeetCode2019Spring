#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int &a, int &b){
    return a>b;
}

class Solution {
public:
    int maximumSwap(int num) {
        if(num<=10) return num;
        int tmp = num;
        vector<int> tmpVec;
        while(tmp){
            tmpVec.push_back(tmp%10);
            tmp /= 10;
        }
        vector<int> oriVec = tmpVec;
        reverse(oriVec.begin(), oriVec.end());
        sort(tmpVec.begin(), tmpVec.end(), cmp);
        int minNum = -1, maxNum = -1;
        for(int i=0; i<oriVec.size(); i++){
            if(oriVec[i]!=tmpVec[i]){
                minNum = oriVec[i];
                maxNum = tmpVec[i];
                break;
            }
        }
        if(minNum==-1) return num;
        for(int i=0; i<oriVec.size(); i++){
            if(oriVec[i]==minNum){
                oriVec[i] = maxNum;
                break;
            }
        }
        for(int i=oriVec.size()-1; i>=0; i--){
            if(oriVec[i]==maxNum){
                oriVec[i] = minNum;
                break;
            }
        }
        int ans = 0;
        for(const int &num: oriVec){
            ans *= 10;
            ans += num;
        }
        return ans;
    }
};