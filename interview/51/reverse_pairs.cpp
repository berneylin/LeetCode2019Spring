#include<vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }

    int mergeSort(vector<int> &nums, int l, int r) {
        if(l>=r) return 0;

        int m = l + (r-l) / 2;
        int lCnt = mergeSort(nums, l, m);
        int rCnt = mergeSort(nums, m+1, r);
        return lCnt+rCnt+mergeArr(nums, l, r, m);

    }

    int mergeArr(vector<int> &nums, int l, int r, int m){
        if(l>=r) return 0;
        int i = m, j = r, idx = r-l, rtnCnt = 0;
        int temp[r-l+1];
        while(i>=l && j>=m+1) {
            if(nums[i] > nums[j]) {
                temp[idx] = nums[i];
                i--;
                rtnCnt += (j-m);
            }else{
                temp[idx] = nums[j];
                j--;
            }
            idx--;
        }
        while(i>=l){
            temp[idx--] = nums[i--];
        }
        while(j>=m+1){
            temp[idx--] = nums[j--];
        }
        int copyIdx = 0;
        while(l<=r) {
            nums[l++] = temp[copyIdx++];
        }
        return rtnCnt;
    }

};