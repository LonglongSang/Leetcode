class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int a[s.length()];
		for(int i=0;i<s.length();++i) a[i]=-1;
		int ret=-1;
		for(int i=1;i<s.length();++i){
			int j;
			for(j=i-1;i>=0;--j){
				if(s[i]==s[j]) break;
			}
			a[i]=j;
			int len=i-j;
			int c;
			for(c=i-1;c>=j;--c){
				if(a[c]>=j)len=i-a[c]; 
			}
			if(len>ret) ret=len;
		}
		return ret;
    }
};
