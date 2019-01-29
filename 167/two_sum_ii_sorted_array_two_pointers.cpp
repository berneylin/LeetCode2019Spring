class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1, thisSum;
        vector<int> ret;
        while(i<j){
            thisSum = numbers[i]+numbers[j];
            if(thisSum==target){
                ret.push_back(i+1);
                ret.push_back(j+1);
                break;
            }else if(thisSum<target) i++;
            else if(thisSum>target) j--;
        }
        return ret;
    }
};