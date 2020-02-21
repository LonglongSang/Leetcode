#include <string>
class Solution {
public:
    void get(string &digits,vector<string> &dp,vector<string> &ret,string &temp,int index,int length){
        if(index!=length){
            for(int i=0;i<dp[digits[index]-'0'].length();i++){
                temp[index]=dp[digits[index]-'0'][i];
                get(digits,dp,ret,temp,index+1,length);
            }
        }else if(index==length){
            ret.push_back(temp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size()==0) return ret;
        vector<string> dp(10);
        string temp=digits;
        //temp.resize(digits.length());
        dp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        get(digits,dp,ret,temp,0,digits.size());
        return ret;
    }
};
