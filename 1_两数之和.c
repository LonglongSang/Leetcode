/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int i,j;
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(nums[i]+nums[j]==target && i!=j) break;
        }
        if(nums[i]+nums[j-1]==target) break;
    }
    int *ret=(int*)malloc(2*sizeof(int));
    ret[0]=i-1;
    ret[1]=j;
    return ret;
}
