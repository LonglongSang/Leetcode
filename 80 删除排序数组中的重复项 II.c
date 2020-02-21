

int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==2) return 2;
    int delete=0;
    int last=nums[0];
    int count=1;
    for(int i=1;i<numsSize;++i){
        if(nums[i]==last){
            count++;
            if(count>2)
                delete++;
            else
                nums[i-delete]=nums[i];    
        }else{
            last=nums[i];
            count=1;
            nums[i-delete]=nums[i];
        }
    }
    return numsSize-delete;
}

