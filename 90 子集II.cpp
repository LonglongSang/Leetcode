class Solution {
public:
    void get(int index,int &count,set<vector<int>> &ret,vector<int>& nums,vector<int> & temp){
        ret.insert(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            get(i+1,count,ret,nums,temp);
            temp.pop_back();
        }
    }    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ret;
        vector<int> temp;
        int count=0;
        get(0,count,ret,nums,temp);
        vector<vector<int>> dp;
        for(auto a:ret) dp.push_back(a);
        return dp;
    }
};
