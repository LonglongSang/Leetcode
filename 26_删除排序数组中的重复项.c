int removeDuplicates(int* nums, int numsSize){
    if(numsSize==1) return numsSize;
    if(numsSize==0) return 0;
    int delete=0;
    int last=nums[0];
    for(int i=1;i<numsSize;++i){
        if(nums[i]==last){
            delete++;
        }else{
            last=nums[i];
            nums[i-delete]=nums[i];
        }
    }
    return numsSize-delete;
}
