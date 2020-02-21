class Solution {
public:
    void cal(vector<int>& dp,vector<int> &temp,vector<int> &factor,int k,int n){
        int index;
        for(int i=0;i<n;i++){
            sort(dp.begin(),dp.end());
            index=k/factor[n-i-1];
            k=k%factor[n-i-1];
            temp.push_back(dp[index]);
            dp[index]=1000;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> dp;
        int n=nums.size();
        vector<int> factor(n+1,1);
        for(int i=1;i<n+1;i++) factor[i]=factor[i-1]*i;
        vector<vector<int>> ret(factor[n]);
        for(int i=0;i<factor[n];i++){
            vector<int> temp;
            dp=nums;
            cal(dp,temp,factor,i,n);
            ret[i]=temp;
        }
        return ret;
    }

};
