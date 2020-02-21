class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.length();
        int len2=needle.length();
        if(len2>len1) return -1;
        if(len2==0) return 0;
        for(int i=0;i<len1-len2+1;++i){
            int count=0;
            std::cout<<i<<endl;
            for(int j=i;count<len2;j++){
                if(haystack[j]==needle[count])
                    count++;
                else
                    break;
            }
            if(len2==count) return i;    
        }
        int pos=-1;
        return pos;
    }
};
