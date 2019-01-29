class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int numbersSize = numbers.size();
        for(int i=0;i<numbersSize-1;i++){
            for(int j=i+1;j<numbersSize;j++){
                if(numbers[i]+numbers[j]==target){
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    break;
                }else if(numbers[i]+numbers[j]>target) break;
            }
        }
        return ret;
    }
};