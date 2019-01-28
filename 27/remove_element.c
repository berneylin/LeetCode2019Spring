int removeElement(int* nums, int numsSize, int val) {
    int delIndex = 0;
    int tmp;
    while(delIndex<numsSize && nums[delIndex]!=val) delIndex++;  /* find the first position to delete */

    for(int i=delIndex+1;i<numsSize;i++){
        if(nums[i]!=val){
            tmp = nums[i];
            nums[i] = nums[delIndex];
            nums[delIndex] = tmp;
            while(delIndex<numsSize && nums[delIndex]!=val) delIndex++; /* find the next position to delete */
        }
    }

    int ret = 0;

    while(ret<numsSize && nums[ret]!=val) ret++;
    return ret;
}