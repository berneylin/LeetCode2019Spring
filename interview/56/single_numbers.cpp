class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int num: nums) 
            ret ^= num;
        int mask = 1;
        while((ret&mask) == 0){
            mask <<= 1;
        }
        int n1 = 0, n2 = 0;
        for (int num: nums){
            if(num&mask) {
                n1 ^= num;
            }else{
                n2 ^= num;
            }
        }
        vector<int> retVec;
        retVec.push_back(n1);
        retVec.push_back(n2);

        return retVec;
    }
};