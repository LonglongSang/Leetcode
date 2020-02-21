class Solution {
public:
    void get(int index,int sum,vector<vector<int>> &ret,vector<int> &temp,int &target,vector<int>& candidates){
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(sum+candidates[i]<target){
                temp.push_back(candidates[i]);
                get(i+1,sum+candidates[i],ret,temp,target,candidates);
                temp.pop_back();
            }else if(sum+candidates[i]==target){
                temp.push_back(candidates[i]);
                ret.push_back(temp);
                temp.pop_back();
                break;
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> temp;
        get(0,0,ret,temp,target,candidates);
        return ret;
    }
};
