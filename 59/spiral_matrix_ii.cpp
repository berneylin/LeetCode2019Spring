#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        int leftB, rightB, upB, downB;
        leftB = 0;
        rightB = n-1;
        upB = 0;
        downB = n-1;

        for(int i=0;i<n;i++){
            vector<int> tmp(n);
            ret.push_back(tmp);
        }

        int cnt = 1;
        int i;
        while(leftB<rightB&&upB<downB){
            i = leftB;
            while(i<rightB) ret[upB][i++] = cnt++;
            i = upB;
            while(i<downB) ret[i++][rightB] = cnt++;
            i = rightB;
            while(i>leftB) ret[downB][i--] = cnt++;
            i = downB;
            while(i>upB) ret[i--][leftB] = cnt++;
            leftB++;rightB--;
            upB++;downB--;
        }
        if(n&1){
            ret[leftB][upB] = cnt++;
        }

        return ret;
    }
};