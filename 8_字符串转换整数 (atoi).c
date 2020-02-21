double FIND_number(char* str,int count){
    double sum=0;
    while(48<=str[count] && str[count]<=57 && str[count]){
        sum=sum*10+(str[count]-48);
        count++;
    }
    return sum;
}
int myAtoi(char * str){
    int MIN=0x80000000;
    int MAX=0x7FFFFFFF;
    int count=0;
    double return_num=0;
    while(str[count]==' ') count++;
    if(str[count]=='-'){
        return_num=-(FIND_number(str,count+1));
    }else if(str[count]=='+'){
        return_num=FIND_number(str,count+1);
    }else if(48<=str[count] && str[count]<=57){
        return_num=FIND_number(str,count);
    }
    if(return_num>MAX){
        return MAX;
    }else if(return_num<MIN){
        return MIN;
    }else{
        return return_num;
    }
}
