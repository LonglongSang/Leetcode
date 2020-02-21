void line_swap(int line,int **matrix,int *matrixColSize);
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize==0 || *matrixColSize==0) return;
    for(int i=0;i<matrixSize;i++){
        line_swap(i,matrix,matrixColSize);
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize-i;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[matrixSize-1-j][matrixSize-i-1];
            matrix[matrixSize-1-j][matrixSize-i-1]=temp;
        }
    }
    
}
void line_swap(int line,int **matrix,int *matrixColSize){
    int low=0,high=matrixColSize[line]-1;
    int temp;
    while(high>low){
        temp=matrix[line][low];
        matrix[line][low]=matrix[line][high];
        matrix[line][high]=temp;
        high--;
        low++;
    }
}
