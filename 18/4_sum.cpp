class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        set<vector<int> > S;
        if(nums.size()<4) return ans;
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        for(int i=0;i<numsSize-3;i++){
            int thisTarget = target - nums[i];
            for(int j=i+1;j<numsSize-2;j++){
                thisTarget -= nums[j];
                int l = j+1, r = numsSize-1;
                while(l<r){
                    int sum = nums[l] + nums[r];
                    if(sum==thisTarget){
                        vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                        if(S.find(tmp)==S.end()){
                            ans.push_back(tmp);
                            S.insert(tmp);
                        }
                        l++;
                    }else{
                        if(sum<thisTarget) l++;
                        else r--;
                    }
                }
                thisTarget += nums[j];
            }
        }
        return ans;
    }
};