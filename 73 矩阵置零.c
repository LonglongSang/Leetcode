void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize==0 || *matrixColSize==0) return;
    int *row=(int *)malloc(sizeof(int)*matrixSize);
    int *col=(int *)malloc(sizeof(int)*(*matrixColSize));
    for(int i=0;i<matrixSize;i++) row[i]=0;
    for(int i=0;i<*matrixColSize;i++) col[i]=0;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            if(matrix[i][j]==0){
                row[i]++;
                col[j]++;
            }
        }
    }
    for(int i=0;i<matrixSize;i++){
        if(row[i]!=0){
            for(int j=0;j<*matrixColSize;j++) matrix[i][j]=0;
        }
    }
    for(int i=0;i<*matrixColSize;i++){
        if(col[i]!=0){
            for(int j=0;j<matrixSize;j++) matrix[j][i]=0;
        }
    }
}
