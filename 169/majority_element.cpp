class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int cnt = 1;
        int numsLength = nums.size();
        for(int i=1;i<numsLength;i++){
            if(cnt==0){
                cnt++;
                ans = nums[i];
            }else{
                if(nums[i]==ans){
                    cnt ++;
                }else{
                    cnt --;
                }
            }
        }
        return ans;
    }
};