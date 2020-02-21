#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
class Solution {
public:
    int factorial(int n){
        int sum=1;
        while(n!=0) sum*=n--;
        return sum;
    }
	string getPermutation(int n, int k) {
        string ret;
        k--;
        string dp="123456789";
		int index,hh;
        for(int i=0;i<n;i++){
            sort(dp.begin(),dp.end());
            hh=factorial(n-i-1);
            index=k/hh;
            k=k%hh;
            ret.push_back(dp[index]);
            dp[index]='e';
        }
		return ret;
    }
};
