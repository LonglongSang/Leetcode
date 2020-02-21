int length(char *sub,int start_pos,int *end);
char * countAndSay(int n){
    int size=5000;
    char *main=malloc(sizeof(char)*size);
    char *sub=malloc(sizeof(char)*size);
    char *temp;
    int count_main=0,count_sub=1;
    sub[0]='1';
    for(int i=2;i<=n;i++){
        int j=0;
        while(j<count_sub){
            int len=length(sub,j,&count_sub);
            main[count_main]='0'+(char)len;
            count_main++;
            main[count_main]=sub[j];
            count_main++;
            j+=len;
        }
        temp=main;
        main=sub;
        sub=temp;
        count_sub=count_main;
        count_main=0;
    }
    
    sub[count_sub++]='\0';
    
    return sub;
}
int length(char *sub,int start_pos,int *end){
    int count=0;
    char key=sub[start_pos];

    while(start_pos<*end && sub[start_pos]==key){
        start_pos++;
        count++;
    }
    return count;
}
