#include<stdio.h>
void move(int* nums, int fromIdx, int endIdx){
    /* move the elements from [k,endIdx] to [k+1, nums.endIdx+1] */
    /* assume that the `nums' array always contains enough space to store moved elements */
    for(int i=endIdx;i>=fromIdx;i--){
        nums[i+1] = nums[i];
    }
}


void merge(int* nums1, int m, int* nums2, int n) {
    int i=0, j=0;
    int targetLength = m + n;
    while(i<m&&j<n){
        while(i<m&&nums1[i]<nums2[j]) i++;  // find the appropriate position to insert
        if(i>=m) break;  // `nums1' has reached the end
        move(nums1, i, m-1);  // move to make space for insert
        nums1[i] = nums2[j];  // make insert
        m++; // modify the length of array `nums1'
        j++; // modify the position of the pointer j
    }
    if(m!=targetLength){  //  `nums2' has not reached the end
        for(int k=i;j<n;j++,k++){
            nums1[k] = nums2[j];  // append the remainder of `nums2' to the tail of `nums1'
        }
    }
}

int main(void){
    int nums1[100], nums2[100];
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++) scanf("%d", &nums1[i]);
    for(int i=0;i<n;i++) scanf("%d", &nums2[i]);
    merge(nums1, m, nums2, n);
    for(int i=0;i<m+n;i++) printf("%d ", nums1[i]);
    return 0;
}