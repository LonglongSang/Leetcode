char * longestCommonPrefix(char ** strs, int strsSize){
    char *ret=(char*)malloc(sizeof(char)*1000);
    int total_count=0;
    if(strsSize==1){
        return strs[0];
    }else if(strsSize==0){
        ret[0]='\0';
        return ret;
    }
    for(int i=0;i<10000;i++){
        int flag=1;
        for(int j=1;j<strsSize;j++){
            if(strs[j][i]=='\0'){
                flag=0;
                break;
        }else{
                if(strs[j][i]!=strs[j-1][i]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            ret[total_count++]=strs[0][i];
        }else{
            break;
        }
    }
    ret[total_count++]='\0';
    return ret;
}
