bool isPalindrome(int x){
    int i=x;
    if(i<0)
        return false;
    int *num[10];
    for(int z=0;z<10;++z)
        num[z]=0;

    int count=-1;
    while(i!=0){
        count++;
        int a=i%10;
        num[count]=a;
        printf("%d",num[count]);
        i-=a;
        i/=10;

    }
    int j=0;
    while(j < count-j){
        if(num[j]!=num[count-j])
            return false;
        j++;
    }
    return true;
}
