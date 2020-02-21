/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int low=0;
    int high=numsSize-1;
    int location=-1;
    int mid;
    int find=0;
    while(high>=low){
        mid=(high+low)/2;
        if(nums[mid]==target){
            find=1;
            break;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    int* ret;
    ret=(int*)malloc(2*sizeof(int));
    ret[0]=-1;
    ret[1]=-1;
    if(find==0) return ret;
    int left_count=0;
    for(int a=mid-1;a>=0;--a){
        if(nums[a]==target)
            left_count++;
        else
            break;
    }
    int right_count=0;
    for(int a=mid+1;a<numsSize;++a){
        if(nums[a]==target)
            right_count++;
        else
            break;
    }
    ret[0]=mid-left_count;
    ret[1]=mid+right_count;
    *returnSize=2;
    printf("%d",ret[0]);
    printf("%d",ret[1]);
    return ret;
}
