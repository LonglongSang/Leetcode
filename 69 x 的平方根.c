int mySqrt(int x){
    if(x<=1) return x;
    int low=0;
    int high=x;
    int mid;
    long a;
    while(high!=low+1){
        mid=(low+high)/2;
        a=(long)mid*(long)mid;
        if(a==x){
            return mid;
        }else if(a>x){
            high=mid;
        }else if(a<x){
            low=mid;
        }
    }
    return low;
}
