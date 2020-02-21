int trap(int* height, int heightSize){
    if(heightSize<=2) return 0;
    int *left,*right;
    left=(int*)malloc(heightSize*sizeof(int));
    right=(int*)malloc(heightSize*sizeof(int));
    left[0]=0;
    right[heightSize-1]=0;
    for(int i=1;i<heightSize-1;++i){
        if(height[i-1]>left[i-1])
            left[i]=height[i-1];
        else
            left[i]=left[i-1];
        if(height[heightSize-i]>right[heightSize-i])
            right[heightSize-i-1]=height[heightSize-i];
        else
            right[heightSize-i-1]=right[heightSize-i];
    }
    int cap=0;
    for(int i=1;i<heightSize-1;++i){
        int small=left[i];
        if(right[i]<left[i]) small=right[i];
        if(small>height[i]) cap+=small-height[i];
    }
    return cap;
}
