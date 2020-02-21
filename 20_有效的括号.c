bool isValid(char * s){
    int i=0;
    int len=0;
    while(s[i]){
        len++;
        i++;
    }
    char* stack;
    stack=(char*)malloc(len*sizeof(char));
    int top=-1;
    char temp;
    
    for(i=0;i<len;++i){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stack[++top]=s[i];
        }else{
            if(top==-1)
                return false;
            temp=stack[top--];
            if(s[i]-1!=temp && s[i]-2!=temp)
                return false;
        }
    }
    if(top!=-1)
        return false;
    return true;
}
