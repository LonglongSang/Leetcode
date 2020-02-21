/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int count=1;
    for(int i=digitsSize-1;i>=0;--i){
        if(count+digits[i]>=10){
            digits[i]=(count+digits[i])%10;
            count=1;
        }else{
            digits[i]=count+digits[i];
            count=0;
        }
    }
    int* p;
    if(count==1){
        printf("%d",10);
        p=(int*)malloc((digitsSize+1)*sizeof(int));
        p[0]=1;
        for(int i=1;i<digitsSize+1;++i) p[i]=digits[i-1];
        *returnSize=digitsSize+1;
        return p;
    }else{
        *returnSize=digitsSize;
        return digits;
    }
}
