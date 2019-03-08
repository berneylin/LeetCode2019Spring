class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max = 0, flag=0;
        for(int i=31;i>=0;i--){
            set<int> bitStore;
            flag |= (1<<i);
            for(int num: nums){
                bitStore.insert(num & flag);
            }
            int tmp = max | (1<<i);
            for(int x: bitStore){
                if(bitStore.find(x ^ tmp)!=bitStore.end()){
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};