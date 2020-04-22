#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int nums[n];
        for(int i=0;i<n;i++) nums[i] = i+1;
        int idx = 1;
        while(idx<k){
            // 生成下一个全排列
            // 首先确定末尾部分最长的递减序列
            int j = n-1;
            while(j>0 && nums[j-1] > nums[j]) j--;
            // 如果j=0 说明已经是最后一个全排列了 返回初始nums就可以，但是这题的条件一定不会触发

            // 从nums[j] 到 nums[n-1] 寻找最小的（即索引最大）比nums[j-1]大的数
            int k = j, tmp = nums[j-1];
            while(k<n-1 && nums[k+1]>tmp) k++;

            // 交换nums[j-1]和nums[k]
            nums[j-1] = nums[k];
            nums[k] = tmp;

            // 逆置 nums[j]到nums[n-1]
            int l = j, r = n-1;
            while(l<=r){
                tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
                r--;
            }

            idx++;
        }
        string ans;

        for(const auto& num: nums) ans.push_back('0'+num);
        return ans;
    }
};