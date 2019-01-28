int removeDuplicates(int* nums, int numsSize) {
    if(!nums || !numsSize) return 0;
    int retLength = 1;
    int i = 1;
    while(i<numsSize){
        if(nums[retLength-1]!=nums[i]){
            nums[retLength++] = nums[i];
        }
        i++;
    }
    return retLength;
}