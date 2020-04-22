#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0.0;
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int len1 = nums1.size(), len2 = nums2.size();
        int iMin = 0, iMax = len1;
        while(iMin<=iMax){
            int i = iMin + ((iMax-iMin)>>1);
            int j = ((len1+len2+1)>>1) - i;
            if(j!=0 && i!=len1 && nums2[j-1]>nums1[i]){
                iMin = i+1;
            }
            else if(i!=0 && j!=len2 && nums1[i-1]>nums2[j]){
                iMax = i-1;
            }
            else{
                int maxLeft = 0;
                if(i==0) maxLeft = nums2[j-1];
                else if(j==0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                if((len1+len2)&1){
                    median = maxLeft;
                    break;
                }

                int minRight = 0;
                if(i==len1) minRight = nums2[j];
                else if(j==len2) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);
                median = (maxLeft+minRight)/2.0;
                break;
            }
        }

        return median;
    }
};