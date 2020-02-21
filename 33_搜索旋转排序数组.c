int find(int *nums,int low,int high,int target){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target){
    if(numsSize==0) return -1;
    if(numsSize==1){
        if(nums[0]==target)
            return 0;
        else
            return -1;
    }
    int pivot=-1;
    for(int i=0;i<numsSize-1;++i){
        if(nums[i]>nums[i+1]){
            pivot=i;
            break;
        }
    }
    int a;
    if(pivot==-1){
        a=find(nums,0,numsSize-1,target);
    }
    a=find(nums,0,pivot,target);
    if(a==-1){
        a=find(nums,pivot+1,numsSize-1,target);
        return a;
    }else{
        return a;
    }
    
}
