void quicksort(int* nums,int low,int high){
    if(low<high){
        int pivot=partition(nums,low,high);
        quicksort(nums,low,pivot-1);
        quicksort(nums,pivot+1,high);
    }

}
int partition(int *nums,int low,int high){
    int pivot=nums[low];
    while(low<high){
        if(nums[high]>=pivot && low<high) --high;
        nums[low]=nums[high];
        if(nums[low]<=pivot && low<high) ++low;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    printf("pivot is %d",low);
    return low;
}
int firstMissingPositive(int* nums, int numsSize){
    quicksort(nums,0,numsSize-1);
    for(int c=0;c<numsSize;++c){
        printf(" %d ",nums[c]);
    }
    int i=0;
    int ret=1;
    for(int j=0;j<numsSize;++j){
        if(ret==nums[j])
            ret++;
        else if(ret>nums[j]){
            if(nums[j]<=0)
                ret=1;
            else
                ret=nums[j]+1;
        } else{
            return ret;
        }

    }
return ret;
}
