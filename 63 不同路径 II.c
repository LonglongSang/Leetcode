int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGridSize==0 && *obstacleGridColSize==0) return 0;
    long path[obstacleGridSize][*obstacleGridColSize];
    if(obstacleGrid[0][0]==0){
        path[0][0]=1;
    }else{
        return 0;
    }
    int count=0;
    for(int i=1;i<obstacleGridSize;i++){
        if(obstacleGrid[i][0]!=1 && count==0){
            path[i][0]=1;
        }else if(obstacleGrid[i][0]==1 && count==0){
            path[i][0]=0;
            count=1;
        }else{
            path[i][0]=0;
        }
        //printf("%d,",path[i][0]);
    }
    printf("\n");
    count=0;
    for(int i=1;i<*obstacleGridColSize;i++){
        if(obstacleGrid[0][i]!=1 && count==0){
            path[0][i]=1;
        }else if(obstacleGrid[0][i]==1 && count==0){
            path[0][i]=0;
            count=1;
        }else{
            path[0][i]=0;
        }
        //printf("%d,",path[i][0]);
    }

    for(int i=1;i<obstacleGridSize;i++){
        for(int j=1;j<*obstacleGridColSize;j++){
            if(obstacleGrid[i][j]!=1){
                path[i][j]=path[i][j-1]+path[i-1][j];
            }else{
                path[i][j]=0;
            }

            //printf("%d,",path[i][j]);
        }
        //printf("\n");
    }
    return path[obstacleGridSize-1][*obstacleGridColSize-1];
}
