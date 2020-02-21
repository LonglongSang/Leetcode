class Solution {
public:
    void get(vector<vector<int>> &ret,vector<int> &temp,int low,int high,int step,int target){
        if(step!=target && high-low+1>=target-step){
            for(int i=low;i<=high;i++){
                temp[step]=i;
                get(ret,temp,i+1,high,step+1,target);
            }
        }else if(step==target){
            ret.push_back(temp);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp(k);
        get(ret,temp,1,n,0,k);
        return ret;
    }
};
