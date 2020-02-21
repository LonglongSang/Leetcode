void traverse(char *s,int index,int len,int *count);
int numDecodings(char * s){
    int len=strlen(s);
    int count=0;
    traverse(s,0,len,&count);
    return count;
}
void traverse(char *s,int index,int len,int *count){
    if(s[index]=='0') return;
    if(index==len-1 || index==len){
        (*count)++;
        return;
    }
    traverse(s,index+1,len,count);
    if(s[index]=='1'){
        if(index+1<len) traverse(s,index+2,len,count);
    }else if(s[index]=='2'){
        if(index+1<len && (int)(s[index+1]-'0')<=6) traverse(s,index+2,len,count);
    }
}
