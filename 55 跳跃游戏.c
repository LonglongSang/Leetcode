bool canJump(int* nums, int numsSize){
    int good[numsSize];
    for(int i=0;i<numsSize;i++) good[i]=0;
    good[numsSize-1]=1;
    for(int i=numsSize-2;i>=0;i--){
        for(int j=i+1;j<numsSize;j++){
            if(good[j]==1){
                if(j-i<=nums[i]){
                    good[i]=1;
                    //printf("%d is good\n",i);
                }
                break;
            }else{
                if(j-i>nums[i]) break;
            }
        }
    }
    if(good[0]==1) return 1;
    return 0;
}
