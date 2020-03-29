#include<vector>
#include<deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ansVec;
        if(nums.empty() || k==0) return ansVec;
        deque<int> monoQ;  // 单调递减队列，存储数组下标
        for(int i=0;i<nums.size();i++){
            int &thisNum = nums[i];
            // 当前数入队列
            while(!monoQ.empty()){
                int &backNum = nums[monoQ.back()];
                if(backNum<thisNum){
                    monoQ.pop_back(); // 队尾元素小于当前元素，为维持递减性，队尾元素出队
                }else{
                    break;
                }
            }
            monoQ.push_back(i);
            // 维护窗口大小
            while(!monoQ.empty()){
                int frontNumIdx = monoQ.front();
                if(i-frontNumIdx>=k){
                    // 队首元素已经不在当前的窗口内了
                    monoQ.pop_front();
                }else{
                    break;
                }
            }

            if(i>=k-1){
                ansVec.push_back(nums[monoQ.front()]);
            }
        }
        return ansVec;
    }
};

/*
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/