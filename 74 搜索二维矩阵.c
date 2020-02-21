void conver(int *index,int *i,int *j,int *matrixColSize);
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize==0 || *matrixColSize==0) return 0;
    int range=matrixSize*(*matrixColSize)-1;
    int low=0;
    int high=range;
    int mid;
    int i,j;
    while(high>=low){
        mid=(low+high)/2;

        conver(&mid,&i,&j,matrixColSize);
        //printf("mid is %d,i %d,j %d\n",mid,i,j);
        if(matrix[i][j]==target){
            return 1;
        }else if(matrix[i][j]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}
void conver(int *index,int *i,int *j,int *matrixColSize){
   *i=*index/(*matrixColSize);
   *j=*index%(*matrixColSize);
}
