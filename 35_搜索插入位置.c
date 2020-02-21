int searchInsert(int* nums, int numsSize, int target){
    int low=0;
    int high=numsSize-1;
    int mid;
    int find=0;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target){
            find=1;
            break;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(find==1){
        return mid;
    }else{
        if(nums[mid]>target)
            return mid;
        else
            return mid+1;
    }

}
