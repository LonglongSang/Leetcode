class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> dp;
        vector<vector<string>> ret;
        string temp;
        for(int i=0;i<strs.size();i++){
            temp=strs[i];
            sort(temp.begin(),temp.end());
            dp[temp].push_back(strs[i]);
        }
        int count=0;
        ret.resize(dp.size());
        for(auto it:dp){
            ret[count++]=it.second;
        }
        return ret;
    }
};
