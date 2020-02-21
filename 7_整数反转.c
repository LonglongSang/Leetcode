int reverse(int x){
    int i=x;
    long sum=0;
    int count=1;
    int counter=0;
    while(i!=0){
        int a=i%10;
        i-=a;
        i/=10;
        sum=sum*10+a;
        count*=10;
    }
    int MAX=0x7FFFFFFF;
    int MIN=0x80000000;
    if(sum>MAX || sum <MIN)
        return 0;
    else 
        return sum;
}
