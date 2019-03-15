class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        if(left>right) return ans;
        while(left<=right){
            int tmp = left;
            bool isValid = true;
            while(isValid && tmp){
                int thisDigit = tmp % 10;
                if(thisDigit==0) isValid = false;
                else{
                    if(left%thisDigit) isValid = false;
                    else tmp/=10;
                }
            }
            if(isValid) ans.push_back(left);
            left++;
        }
        return ans;
    }
};