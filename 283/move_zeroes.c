void moveZeroes(int* nums, int numsSize) {
    int nonZeroLength = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[nonZeroLength++] = nums[i];
        }
    }
    while(nonZeroLength<numsSize){
        nums[nonZeroLength++] = 0;
    }
}