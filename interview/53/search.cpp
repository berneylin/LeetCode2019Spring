class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return 0;
        }
        int l = 0, r = nums.size() - 1, pos = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]==target){
                pos = m;
                break;
            }
            else if (nums[m]<target){
                l = m+1;
            }else if (nums[m]>target){
                r = m-1;
            }
        }
        if(pos==-1){
            return 0;
        }
        int cnt = 0;
        l = pos; r = pos+1;
        while(l>=0 && nums[l]==target) {
            cnt++;
            l--;
        }
        while(r<=nums.size()-1 && nums[r]==target){
            cnt++;
            r++;
        }
        return cnt;
    }
};