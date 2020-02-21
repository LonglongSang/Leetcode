/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void forward(int index1,int index2,int **matrix,int **path,char dir,int *matrixSize,int *matrixColSize,int *count,int *ret);
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int size=matrixSize*(*matrixColSize);
    int *ret;
    if(matrixSize==0 || *matrixColSize==0){
        *returnSize=0;
        return ret;
    }
    int **path;
    path=(int**)malloc(sizeof(int*)*matrixSize);
    for(int i=0;i<matrixSize;i++) path[i]=(int*)malloc(sizeof(int)*(*matrixColSize));
    for(int i=0;i<matrixSize;i++)
        for(int j=0;j<*matrixColSize;j++)
            path[i][j]=0;//sign as un walk
    ret=(int*)malloc(sizeof(int)*size);
    int count=0;
    forward(0,0,matrix,path,'r',&matrixSize,matrixColSize,&count,ret);
    *returnSize=count;
    return ret;
}
void forward(int index1,int index2,int **matrix,int **path,char dir,int *matrixSize,int *matrixColSize,int *count,int *ret){
    path[index1][index2]=1;
    ret[*count]=matrix[index1][index2];
    (*count)++;
    switch(dir){
        case 'r':
            if(index2+1<*matrixColSize && path[index1][index2+1]==0) forward(index1,index2+1,matrix,path,'r',matrixSize,matrixColSize,count,ret);
            break;
        case 'l':
            if(index2-1>=0 && path[index1][index2-1]==0)   forward(index1,index2-1,matrix,path,'l',matrixSize,matrixColSize,count,ret);
            break;
        case 'u':
            if(index1-1>=0 && path[index1-1][index2]==0)  forward(index1-1,index2,matrix,path,'u',matrixSize,matrixColSize,count,ret);
            break;
        case 'w':
            if(index1+1<*matrixSize && path[index1+1][index2]==0)  forward(index1+1,index2,matrix,path,'w',matrixSize,matrixColSize,count,ret);
            break;
        default:
            break;
    }
            if(dir!='l' && index2+1<*matrixColSize && path[index1][index2+1]==0){//向右走
                forward(index1,index2+1,matrix,path,'r',matrixSize,matrixColSize,count,ret);
            }else if(dir!='u' && index1+1<*matrixSize && path[index1+1][index2]==0){//向下走
                forward(index1+1,index2,matrix,path,'w',matrixSize,matrixColSize,count,ret);
            }else if(dir!='r' && index2-1>=0 && path[index1][index2-1]==0){//向左走
                forward(index1,index2-1,matrix,path,'l',matrixSize,matrixColSize,count,ret);
            }else if(dir!='w' && index1-1>=0 && path[index1-1][index2]==0){//向上走
                forward(index1-1,index2,matrix,path,'u',matrixSize,matrixColSize,count,ret);
            }else{//无路可走
                return;
            }

}
