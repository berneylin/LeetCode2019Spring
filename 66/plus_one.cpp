class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digitSize = digits.size();
        int currSum, carry = 1;
        for(int i=digitSize-1;i>=0;i--){
            currSum = digits[i] + carry;
            if(currSum==10){
                digits[i] = 0;
            }else{
                digits[i] = currSum;
                carry = 0;
                break;
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};