bool search(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;++i){
        if(target==nums[i]) return 1;
    }
    return 0;
}
