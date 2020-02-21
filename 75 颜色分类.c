void swap(int *i,int *j,int *nums);
void swap_advance(int i,int *nums);
void sortColors(int* nums, int numsSize){
    if(numsSize<=1) return;
    int index2=numsSize;
    int index=0;
    while(index!=index2){
        if(nums[index]==0){
            swap_advance(index,nums);
            index++;
        }else if(nums[index]==1){
            index++;
        }else if(nums[index]==2){
            index2--;
            swap(&index,&index2,nums);
        }
    }
}
void swap_advance(int i,int *nums){
    while(i-1>=0 && nums[i]!=nums[i-1]){
        nums[i-1]+=nums[i];
        nums[i]=nums[i-1]-nums[i];
        nums[i-1]=nums[i-1]-nums[i];
        i--;
    }
}
void swap(int *i,int *j,int *nums){
    int a=nums[*i];
    nums[*i]=nums[*j];
    nums[*j]=a;
}
