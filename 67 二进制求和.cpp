#include <algorithm>
class Solution {
public:
    string addBinary(string a, string b) {
        int size_a=a.length();
        int size_b=b.length();
        int big=a.length();
        if(b.length()>big) big=b.length();
        for(int i=0;i<big-size_a;i++) a="0"+a;
        for(int i=0;i<big-size_b;i++) b="0"+b;
        string ret;
        int up=0,temp;
        for(int i=big-1;i>=0;i--){
            temp=up+a[i]+b[i]-'0'-'0';
            ret.push_back(temp%2+'0');
            up=temp/2;
        }
        if(up!=0) ret.push_back(up+'0');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
