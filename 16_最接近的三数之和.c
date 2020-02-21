int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //由小到大排序
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(int),cmp);
    int best_dist=0x7FFFFFFF;
    int ret;
    int temp;
    for(int i=0;i<numsSize-2;++i){
        int left=i+1;
        int right=numsSize-1;
        while(right>left){
            temp=nums[i]+nums[left]+nums[right];
            int dev=abs(temp-target);
            if(dev<best_dist){
                best_dist=dev;
                ret=temp;
            }
            if(temp-target>0){
                right--;
            }else if(temp-target<0){
                left++;
            }else{
                return ret;
            }
        }
    }
    return ret;
}
