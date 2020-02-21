#include <string.h>
int lengthOfLastWord(char * s){
    int count=0;
    int len=0;
    while(s[len]!='\0'){
        len++;
    }
    if(len==0) return 0;
    int start=0;
    int end=len-1;
    while(s[start]==' '){
        start++;
        if(start==len) return 0;
    }
    while(s[end]==' ') end--;
    printf("%d,\n",len);
        for(int i=start;i<=end;i++){
        if(s[i]==' '){
            count=0;
        }else{
            count++;
        }
    }
    
    return count;

    return 111;
}
