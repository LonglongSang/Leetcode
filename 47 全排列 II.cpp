#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void have(vector<vector<int>> &ret,unordered_map<int,int> &dp,int sum,vector<int> &temp){
        bool right=false;
        unordered_map<int,int>::iterator it=dp.begin();
        while(it!=dp.end()){
            if(it->second>0){
                it->second--;
                temp[sum]=it->first;
                have(ret,dp,sum+1,temp);
                it->second++;
                right=true;
            }
            it++;
        }
        if(right==false) ret.push_back(temp);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		unordered_map<int,int> dp;
        for(int i=0;i<nums.size();i++) dp[nums[i]]++;
        vector<vector<int>> ret;
        vector<int> temp(nums.size());
        have(ret,dp,0,temp);
        return ret;
    }
};
