#include <algorithm>
#include <iostream>
class Solution {
public:
    int have(vector<int>& nums,int index){
        int ret=-1;
        int small=1000;
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]>nums[index] && nums[i]<small){
                ret=i;
                small=nums[i];
            }
        }
        return ret;
    }
    void nextPermutation(vector<int>& nums) {
        bool right=false;
        int temp,check;
        for(int i=nums.size()-2;i>=0;i--){
            check=have(nums,i);
            if(check!=-1){
                temp=nums[check];
                nums[check]=nums[i];
                nums[i]=temp;
                right=true;
                //cout<<i<<" "<<check<<endl;
                sort(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(right==false) sort(nums.begin(),nums.end());
    }
};
