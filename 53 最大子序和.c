int maxSubArray(int* nums, int numsSize){
    if(numsSize==1) return nums[0];
    int pre=nums[0];
    int big=0x80000000;
    for(int i=1;i<numsSize;i++){
        if(pre>big) big=pre;
        if(pre+nums[i]>=nums[i]){
            pre=pre+nums[i];
        }else{
            pre=nums[i];
        }
        
    }
    if(pre>big) big=pre;

    return big;
}
