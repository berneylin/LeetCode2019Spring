class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        int current = 0;
        while(current<=end){
            if(nums[current]==0){
                swap(nums, current, begin);
                begin++;
                current++;
            }else if(nums[current]==1){
                current++;
            }else if(nums[current]==2){
                swap(nums, current, end);
                end--;
            }
        }
    }
private:
    void swap(vector<int> &nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};