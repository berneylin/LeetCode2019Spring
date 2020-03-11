class Solution {
public:
    int calcBits(int x){
        int rtn = 1, base = 10;
        while(x / base != 0){
            rtn++;
            base *= 10;
        }
        return rtn;
    }
    vector<int> printNumbers(int n) {
        int i = 1;
        vector<int> rtnVec;
        while(calcBits(i) <= n) {
            rtnVec.push_back(i++);
        }
        return rtnVec;
    }
};